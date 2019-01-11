
function fizzbuzz() {
    let result = '';
    for(let i = 0; i < 100; i++) {
        if(i % 3 == 0) result += 'fizz';
        if(i % 5 == 0) result += 'buzz ' + i + "\n";
    }
    return result || 0;
}

console.log(fizzbuzz());