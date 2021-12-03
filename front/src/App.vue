<template>
  <div id="app">
    <h2>门禁监控</h2>
    <router-view></router-view>
  </div>
</template>


<script>
export default {
  name: 'App',
  data(){
    return{
    }
  },
  mounted(){
    this.screenWidth = document.body.clientWidth;
    this.screenHeight = document.body.clientHeight;
    window.onresize = () => {
      return (() => {
        this.screenWidth = document.body.clientWidth;
        this.screenHeight = document.body.clientHeight;
      })();
    };
  },
  metaInfo() {
      return {
          title: '门禁监控',
          titleTemplate: title => {
              return title
          }
      }
  }

}
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}
</style>