<template>
  <div class="black-bg" v-if="addPage">
    <div class="white-bg"> 
      <h4>상세페이지</h4>
      <p v-if="addPage">{{rooms[addPageNum].content}}</p>
      <button v-if="addButton" @click="addButton=false;addPage=false">닫기</button>
    </div>
  </div>
  <div class="menu">
    <a v-for="menu in menus" :key="menu">{{menu}}</a>
  </div>

  <div v-for="(room,index) in rooms" :key="room">
    <img :src="room.image">
    <h4 class="red" :style="스타일" @click="addPage=true;addButton=true;addPageNum=index">{{room.title}}</h4>
    <p>{{room.price}} 원</p>
    <button v-on:click="increase(index)">허위매물신고</button> <span>신고수 : {{report[index]}}</span>
  </div>


</template>

<script>
import roomData from './assets/data.js';
ㅊ
export default {
  name: 'App',
  data() {
    return {
      addPage : false,
      addPageNum : 0,
      addButton : false,
      report : [0,0,0,0,0,0],
      스타일 : 'color : blue',
      menus : ['Home', 'Shop', 'About'],
      // name, value
      rooms : roomData,
    }

  },
  methods : {
    increase(index) {
      this.report[index]++
    },
    getImgUrl(index) {     
      return require(this.images[index])
    },
    getSrc : function(index){
      // require()으로 묶어줌.
      return require('./assets/room'+index+'.jpg');
    },

  },
  components: {

  }
}
</script>

<style>
body {
  margin : 0
}
div {
  box-sizing:border-box;
}
.black-bg {
  width: 100%; height: 100%;
  background: rgba(0,0,0,0.5);
  position: fixed; padding: 20px;
}
.white-bg {
  width: 100%; background: white;
  border-radius: 8px;
  padding: 20px;
}
.room-img {
  width: 100%;
  margin-top: 40px;
}
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}
.menu {
  background : darkslateblue;
  padding: 15px;
  border-radius: 5px;
}
.menu a {
  color: white;
  padding: 10px;
}
</style>
