<template>
  <div>
    <input type="search" @keyup="checkEnter($event)" v-model="searchText" />
    <br />
    <input type="search" @keyup.enter="doSearch()" v-model="searchText" />
    <button @click="doSearch">조회</button>
    <button type="submit" @click.prevent="doSearch">이게뭔진모름</button>
  </div>
</template>
<script>
// enter, delete, down, esc, 화살표... 주요 키에 대해 바로 이벤트를 받아 함수 호출 가능
// .stop - event.stopPropagation()
// .prevent - event.preventDefault()
export default {
  name: '',
  components: {},
  data() {
    return {
      searchText: ''
    }
  },
  setup() {},
  created() {},
  mounted() {},
  unmounted() {},
  methods: {
    doSearch() {
      console.log(this.searchText)
    },
    checkEnter(event) {
      if (event.keyCode === 13) {
        this.doSearch()
      }
    }
  }
}
</script>
