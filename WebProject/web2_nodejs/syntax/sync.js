var fs = require('fs');

// ***************** 동기 Synchronous: 끝나고 다음꺼
// readFileSync

// console.log('A');
// var result = fs.readFileSync('syntax/sample.txt', 'utf8');
// console.log(result);
// console.log('C');


// ***************** 비동기 Asynchronous: 끝나는 것을 기다리지 않음
// 파일을 읽고 함수를 실행시키며
// 에러가 있으면 err 를 전달
// 아니라면 파일의 내용을 result 에 전달
console.log('A');
fs.readFile('syntax/sample.txt', 'utf8', function(err, result){
    console.log(result);
});
console.log('C');