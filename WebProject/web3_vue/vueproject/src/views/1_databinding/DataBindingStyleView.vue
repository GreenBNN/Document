<template>
  <div>
    <h3>데이터 바인딩 스타일 적용할 때 오브젝트들로 적용함</h3>
    <div style="color: red; font-size: 30px">
      스타일 바인딩: 글씨는 red, 폰트크기: 30px
    </div>
    <div :style="style1">스타일 바인딩: 글씨는 green, 폰트크기: 30px</div>
    <button @click="style1.color = 'blue'">색상바꾸기</button>
  </div>
</template>
<script>
export default {
  name: '',
  components: {},
  data() {
    return {
      style1: {
        color: 'green',
        fontSize: '30px'
      }
    }
  },
  setup() {},
  created() {},
  mounted() {},
  unmounted() {},
  methods: {}
}
</script>
