
// ./는 디폴트 생략가능 현재 디렉토리
var testFolder = './data';
var fs = require('fs');

fs.readdir(testFolder, function(error, filelist) {
    console.log(filelist);
})