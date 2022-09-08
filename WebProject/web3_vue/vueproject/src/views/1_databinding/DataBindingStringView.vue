<template>
  <div>
    <h3>담아둔 문자 데이터를 html 에서 사용하기</h3>
    <h2>Hello {{ userName }}</h2>
    <p>{{ message }}</p>
  </div>
</template>
<script>
export default {
  data() {
    return {
      userName: 'John Doe',
      message: 'Welcome 개발자의 품격',
      arr: [],
      obj: {}
    }
  }
}
</script>
<style scoped>
.text-red {
  color: red;
}
</style>
