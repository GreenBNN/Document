<template>
  <div>
    <h3>
      양방향 데이터 바인딩 / 사용자가 선택하는 것으로 데이터가 바뀌고 표시됨
    </h3>
    <select name="" id="" v-model="selectedCity">
      <option value=""></option>
      <option value="02">서울</option>
      <option value="051">부산</option>
      <option value="064">제주</option>
    </select>
    <br />
    <br />
    <input type="text" :value="name" @input="name = $event.target.value" />
    <p>{{ name }}</p>
  </div>
</template>
<script>
export default {
  name: '',
  components: {},
  data() {
    return {
      selectedCity: '02',
      name: ''
    }
  },
  setup() {},
  created() {},
  mounted() {},
  unmounted() {},
  methods: {}
}
</script>
