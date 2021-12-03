<template>
  <div id="pc">
    <!-- <video ref="video" width="100%" height="640" controls></video> -->
    <iframe style="width:400px;height:300px" ></iframe>
    <iframe style="width:400px;height:300px" ></iframe>

    <div style="margin-top: 20px" >
    <button style="" class="button" @click="openDoor('aDoor')">打开A栋大门</button>
    <button style="margin-left: 200px;" class="button" @click="openDoor('bDoor')">打开B栋大门</button>
    </div>


<div class="music-player">
    <audio
      ref="audio"
      src="@/assets/yisell_sound.mp3"
      preload
      id="audio"
      muted
    ></audio>
  </div>


  </div>
</template>

<script>
// import Hls from 'hls.js'
import axios from 'axios'
export default {
  name: 'PC',
  data(){
    return{
    }
  },
  created(){
      
  },
  components: {
  },
  methods:{
    checkDevice(){
      // console.log("pc checkDevice");
      if(this._isMobile() && this.$router.path !="/m"){
        this.$router.push({path:"/m"})
      }
    },
    _isMobile() {
      let flag = navigator.userAgent.match(/(phone|pad|pod|iPhone|iPod|ios|iPad|Android|Mobile|BlackBerry|IEMobile|MQQBrowser|JUC|Fennec|wOSBrowser|BrowserNG|WebOS|Symbian|Windows Phone)/i)
      return flag;
    },
    openDoor(door){
      console.log("door: ",door)
      axios.get('/open/'+door).then(function(res){
          console.log(res);
          document.getElementById('audio').play()      
      },function(){
          console.log('请求失败处理');
      });
    }
  },
  mounted() {
    this.checkDevice()
    window.onresize = this.checkDevice

    // let hls = new Hls();
    // let stream = "http://127.0.0.1:8888/bDoor/stream.m3u8";
    // let video = this.$refs["video"];
    // hls.loadSource(stream);
    // hls.attachMedia(video);
    // hls.on(Hls.Events.MANIFEST_PARSED, function () {
    //   video.play();
    // });
  },
}
</script>

<style>
.button {
    cursor: pointer; /* 指针/手形图标 */
    border-radius: 4px;
    background-color: #4CAF50; /* Green */
    border: none;
    color: white;
    padding: 15px 32px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    font-size: 16px;
}

.button:hover {
    box-shadow: 0 12px 16px 0 rgba(0,0,0,0.24), 0 17px 50px 0 rgba(0,0,0,0.19);
}
</style>