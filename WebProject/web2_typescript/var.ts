let 이름 :{name : string} ={name : 'kim'};
let 숫자 :number[] = [1, 2, 3];

// type 타입 = string | number; 가능
let 성 : string | number  = 123;

function 함수(x: number) : number {
    return x*2;
}
// 함수('1'); error

type Member = [number, boolean];
let john:Member = [123, true];

type Member2 = {
    [key :string] : string // 무든 string key 는 string value 를 가져야함
}
let person :Member2 = {name : 'kim', age:'123'};

class User {
    name : string;
     constructor(name) {
        this.name = name;
     }
}