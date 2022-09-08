<template>
  <div>
    <h3>클래스 바인딩 / 클래스의 이름 : true 면 클래스가 적용됨</h3>
    <h3>
      사용자의 행위에 대해 클랙스를 만들어 두고 true 가 될 때 적용되게 해준다
    </h3>
    <div :class="{ 'text-red': hasError, active: isActive }">클래스 바인딩</div>
    <button @click="isActive = !isActive">버튼</button>
    <div :class="class2">클래스 바인딩2</div>
  </div>
</template>
<script>
export default {
  name: '',
  components: {},
  data() {
    return {
      isActive: false,
      hasError: false,
      class2: ['active', 'hasError']
    }
  },
  setup() {},
  created() {},
  mounted() {},
  unmounted() {},
  methods: {}
}
</script>
<style scoped>
.active {
  background-color: greenyellow;
  font-weight: bold;
}
.text-red {
  color: red;
}
</style>
