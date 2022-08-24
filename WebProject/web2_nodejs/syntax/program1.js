// parameters 를 전달하는 것
var args = process.argv;
console.log(args);
console.log(args[2]);

console.log('A');
console.log('B');

console.log('C1');
//or
//console.log('C2');

if(args[2] === '1') {
    console.log('is 1');
}
else {
    console.log('is not 1');
}

