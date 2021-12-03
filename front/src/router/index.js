import Vue from 'vue'
import Router from 'vue-router'
import Mobile from '@/mobile'
import PC from '@/pc'
Vue.use(Router)

export const constantRoutes = [
    {
        path: '/m',
        component: Mobile,
        meta: {title: "门禁监控", icon: "setting-o", link: null},
    },
    {
        path: '/',
        component: PC,
        meta: {title: "门禁监控", icon: "setting-o", link: null},
    }
]


const router = new Router({
    mode: 'hash', // 去掉url中的#
    scrollBehavior: () => ({ y: 0 }),
    routes: constantRoutes
  })
  
  
  router.beforeEach((to, from, next) => {
    next()
  })
  
  export default router