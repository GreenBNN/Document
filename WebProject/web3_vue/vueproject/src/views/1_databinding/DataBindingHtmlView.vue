<template>
  <div>
    <h3>담아둔 html 코드 데이터를 문자가 아니라 코드로 쓰기</h3>
    <div>{{ htmlString }}</div>
    <div v-html="htmlString"></div>
  </div>
</template>
<script>
export default {
  name: '',
  components: {},
  data() {
    return {
      htmlString: '<p style="color:red;"> 빨간색 문자 </p>'
    }
  },
  setup() {},
  created() {},
  mounted() {},
  unmounted() {},
  methods: {}
}
</script>
