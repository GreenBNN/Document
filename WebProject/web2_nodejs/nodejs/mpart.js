var M = {
    v:'v',
    f:function(){
        console.log(this.v);
    }
}

// 이 파일 참조하면 M 을 내보낸다
module.exports = M;
