#include "fcpp.hh"
#include "save_image.hh"

//// Teil a)

// Datentyp fuer komplexe Zahlen bestehend aus Real- und Imaginaerteil
struct Complex
{
  float real;
  float imag;
};

// Erzeuge eine komplexe Zahl mit Realteil re und Imaginaerteil im
Complex erzeuge_complex( float re, float im )
{
  Complex t;
  t.real = re; t.imag = im;
  return t;
}

// Syntaktischer Zucker
float real( Complex q ) { return q.real; }
float imag( Complex q ) { return q.imag; }

// Summiert zwei komplexe Zahlen p und q und schreibt das Ergebnis in p
void add_complex(Complex &p, Complex q) 
{
  p.imag = p.imag + q.imag;
  p.real = p.real + q.real;
}

// Multipliziert zwei komplexe Zahlen p und q und schreibt das Ergebnis in p
void multiply_complex(Complex &p, Complex q)
{
  p.real = p.real * q.real - q.imag * q.imag;
  q.imag = p.real * q.imag + q.real * p.imag;
}

// Berechnet einen Schritt der Mandelbrot-Folge fuer die komplexe Zahl
// c, gegeben dem aktuellen Folgenelement z und schreibt das Ergebnis in z
void schritt(Complex &z, Complex c) 
{
  multiply_complex(z,z);
  add_complex(z,c);
}

// Betrag einer komplexen Zahl
float betrag(Complex z) {
  float result = 0;
  result = sqrtf((z.real*z.real) + (z.imag*z.imag));
  std::cout << "real: z.real " << z.real*z.real << " img " << z.imag*z.imag << " result = " << result;
  return result;
}

// Betrag des n-ten Elements der Mandelbrot-Folge zu c
float trajektorie( Complex c, int n )
{
  float result;
  Complex z_0 {0,0};
  for(int i = 0; i < n; i++) {
    // printf("z_imag %.0f z_real %.0f betrag(z_0) = %.6f schritt(z_0,c) = %f \n", z_0.imag, z_0.real, betrag(z_0));
    schritt(z_0, c);
  }
  result = betrag(z_0);
  return result;
}

//// Teil b)

// Datentyp fuer Bilder der Hoehe H und Breite W
struct Image {
  int H, W;
  float** pixel;
};

// Erzeugt ein neues Bild der Hoehe H und Breite W
Image create_image(int H, int W) {
  // float * pixels = new float[H*W];
  // Image bild {H, W, pixels};
  // return bild;
  float ** pixels = new float*[W];
  for(int i = 0; i < W; i++) {
    pixels[i] = new float[H];
  }
  Image bild {H, W, pixels};
  for(int i = 0; i< W; i++) {
    delete pixels[i];
  }
  delete pixels;
  return bild;
}

// Wert eines Bildes I in der i-ten Zeile und j-ten Spalte
float get_pixel( Image bild, int i, int j) {
  return bild.pixel[i][j];
}

// Setzt den Wert von Bild I in der i-ten Zeile und j-ten Spalte auf den
// Wert value
void set_pixel(Image &bild, int i, int j, float value) {
  bild.pixel[i][j] = value;
}

// //// Teil c)

// // Initialisiert die Werte zweier Bilder x_coords und y_coords, so dass die
// // Pixel den x und y Koordinaten eines Gitters (x_min, x_max, y_min, y_max)
// // entsprechen. D.h. links oben entspricht (x_min, y_min), rechts oben
// // (x_max, y_min), links unten (x_min, y_max) und rechts unten (x_max,
// // y_max)

void init_grid(Image &x_coords, Image &y_coords, float x_min, float x_max, float y_min, float y_max) {

  float x_coords_frac = x_max/x_coords.W;
  for(int i = 0; i < x_coords.H; i++) {
    for(int j = 0; j <= x_coords.W; j++) {
      if(j == 0) {
        set_pixel(x_coords, i, j, x_min);
      } else {
        set_pixel(x_coords, i , j, x_coords_frac * j);
      } 
      printf(" %f ", x_coords.pixel[i][j]);
    }
    print("\n");
  }

  float y_coords_frac = y_max/(y_coords.H - 1.0);
  for(int i = 0; i < y_coords.H; i++) {
    for(int j = 0; j <= y_coords.W; j++) {
      if(i == 0) {
        set_pixel(y_coords, i, j, y_min);
      } else {
        set_pixel(y_coords, i, j, y_coords_frac * i);
      }
      printf(" %f ", x_coords.pixel[i][j]);
    }
    print("\n");
  }

  std::cout << "Marcos e smarico";
//   // TODO Iterieren Sie ueber Zeilen und Spalten und nutzen Sie obige
//   // set_pixel Funktion
  // Image  * x_coords_copy = new Image();
  // Image * y_coords_copy = new Image();
  // x_coords_copy = &x_coords;
  // y_coords_copy = &y_coords;

  // std::cout << x_coords.pixel[0][0];
  // print("starts x_coords");
  // //initialize x_coords
  // for(int i = 0; i < x_coords_copy->H;i++) {
  // float x_coords_fraction = x_max/x_coords_copy->W;
  //   for(int j = 0; j <= x_coords_copy->W; j++) {
  //     if(j == 0) {
  //       set_pixel(x_coords, i, j, x_min);
  //     }else {
  //       set_pixel(x_coords, i, j, x_coords_fraction * j);
  //     }
  //     printf(" %.2f ", x_coords_copy->pixel[i][j]);
  //   }
  //   print("\n");
  // }

  // print("starts y_coords");
  // // float y_coords_franction_fraction = y_coords_copy->H - 1 + 0.0;
  // float y_coords_fraction = y_max/y_coords_copy->H;
  // // std::cout << y_coords_fraction;
  // for(int i = 0; i < y_coords_copy->H;i++) {
  //   for(int j = 0; j <= y_coords_copy->W; j++) {
  //     if(i == 0) {
  //       set_pixel(*y_coords_copy, i, j, y_min);
  //     } else {
  //       // std::cout << " " << y_coords_copy->H << " " << y_max/(y_coords_copy->H - 1.0) << " asdf ";
  //       set_pixel(*y_coords_copy, i, j, y_max);
  //       print(y_coords_fraction);
  //     }
  //     printf( " %.2f ", y_coords_copy->pixel[i][j]);
  //   }
  //   y_coords_fraction *= i;
  //   // print(y_coords_fraction);
  //   print("\n");
  // }



}

// // Reduziert Hoehe und Breite eines Bildes I um einen Faktor 2.
// void downsample(/* TODO typ I */) {
//   // TODO Skalieren Sie das Bild und achten Sie darauf Speicherplatz
//   // effizient zu nutzen, d.h. nach der Operation soll kein ungenutzer
//   // Speicherplatz mehr reserviert sein.
// }

int main()
{
  // int H = 256;
  // int W = 256;
  // int N = 100;
  // float xmin = -1.5,
  //       xmax =  0.5,
  //       ymin = -1.0,
  //       ymax =  1.0;

  // TODO b) Erzeugen und initialisieren Sie x_coords und y_coords
  // TODO c) Erzeugen Sie ein Bild bild, welches den Betrag des N-ten
  //         Elements der Mandelbrot Folge visualisiert

  // save_image("bild.png", bild.pixel, bild.W, bild.H);
  // TODO d) Nutzen Sie downsample um das Bild bild herunterzuskalieren
  // save_image("bild_klein.png", bild.pixel, bild.W, bild.H);

  Image x_coords = create_image(4,4);
  Image y_coords = create_image(3,3);
  init_grid(x_coords, y_coords, 0.0, 1.0, 0.0, 1.0);
  // for(std::size_t i = 0; i < (sizeof(test.pixel)/sizeof(*test.pixel)); i++) {
  //   for(std::size_t j = 0; j < (sizeof(*test.pixel)/sizeof(test.pixel[0])); j++) {
  //       printf("Pixels = %f index = %i \n", test.pixel[i]);
  //   }
  // } 
  return 0;
}
