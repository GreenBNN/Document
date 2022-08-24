
// function a() {
//     console.log('A');
// }

// slowfunc 라는 함수가 실행 되고 -> a라는 함수를 실행시키기 위해 callback 사용
// 비동기적인 방식
// 왜냐하면 slowfunc 끝나고 callback 시작 사이에 다른 것들 진행하니까
// 모든 코드는 동기식처럼 생각했는데
// callback 을 쓰는 방식만 비동기식 느낌인듯?

var a = function() {
    console.log('A');
}

function slowfunc(callback) {
    callback();
}
console.log('1');
slowfunc(a);
console.log('3');

