邮箱:wangchuang@pateo.com.cn
密码:wc123456789
----------------------------------
JIRA系统登陆地址：
内网URL：
http://jira.pateo.com.cn/secure/Dashboard.jspa
外网URL：
http://210.22.130.125:8080

王闯
用户名：wangchuang
svn/git密码：K5vkj836
密码：newYu=168

------------------------------------

gerrit
http://10.10.96.213:8081
http://10.10.96.214:8081
 
svn 地址：
svn checkout "http://10.10.96.206/svn/C53FB"

svn checkout "http://10.10.96.206/svn/B1031H"

svn checkout "http://10.10.96.206/svn/C3005S"

命令  svn update

-----------------------jar包与aar包------------------------------
git clone ssh://wangchuang@10.10.96.214:29418/projects/DLS-Auto-QingOS/sdk_release -b e0004h

git clone ssh://wangchuang@10.10.96.213:29418/projects/QingGan_BJEV_APP/os_extends/libs_release -b e0004h

git clone ssh://wangchuang@10.10.96.213:29418/projects/DLS-Auto-APP-Core/output -b e0004h

----------------------项目   一定要加分支号----------------------------
// 空调
git clone ssh://wangchuang@10.10.96.213:29418/projects/QingGan_BJEV_APP/packages/apps/BjevAirConditioner -b e0004h

// 语音记事本
git clone ssh://wangchuang@10.10.96.213:29418/projects/QingGan_BJEV_APP/packages/apps/BjevAudioNote -b e0004h_sop

// 应用商店
git clone ssh://wangchuang@10.10.96.213:29418/projects/QingGan_BJEV_APP/packages/apps/BjevAppStore -b e0004h
 
// 车况
git clone ssh://wangchuang@10.10.96.213:29418/projects/QingGan_BJEV_APP/packages/apps/BjevVehicle -b e0004h

// 收音机
git clone ssh://wangchuang@10.10.96.213:29418/projects/QingGan_BJEV_APP/packages/apps/BjevRadio -b e0004h

// 航旅
git clone ssh://wangchuang@10.10.96.213:29418/projects/QingGan_BJEV_APP/packages/apps/BjevAirTripService -b e0004h

// tablayout三方控件
git clone ssh://wangchuang@10.10.96.213:29418/projects/QingGan_BJEV_APP/packages/middlewares/TabMenuLib -b e0004h

// toast三方控件
git clone ssh://wangchuang@10.10.96.213:29418/projects/QingGan_BJEV_APP/packages/middlewares/BjevWidget_new -b e0004h


git clone ssh://wangchuang@10.10.96.213:29418/projects/QingGan_BJEV_APP/packages/apps/BjevLogin -b e0004h

git clone ssh://wangchuang@10.10.96.213:29418/projects/QingGan_BJEV_APP/packages/apps/BjevUserCenter -b e0004h

// 机子
sudo minicom -D  /dev/ttyUSB0 

root
pateo2018

// 不需要每次都login 和 password
setprop persist.sys.no_login yes

// 挂载 这步千万不能少
otg_control 1   

// 打开权限 读写
adb remount   

// 刷机
reboot recovery

// 改变本地激活状态
nvdata -w acted true

nvdata -w vin VNNC53TEST9999002

nvdata -r vin

// 查看log
beginning of system  

grep -rni Androidruntime

logcat | grep -i okhttp

// 抓log
adb logcat  > /home/wangchuang/1.txt

// app冷启动
Displayed

---------------------- 编译jar包------------------
./build.sh -r TabMenuLib/tabmenulib

./build.sh -r BjevWidget_new/Widget

// 窗口启动广播
am broadcast -a com.pateo.bjev.ACTION_SECOND_BOOT
am broadcast -a com.pateo.bjev.ACTION_LAUNCHER_BOOT

---------------------- 空调 打包 运行------------------
//打包
./build.sh -r BjevAirConditioner/app;adb install -r ../OUT_APP/BjevAirConditioner-release-signed.apk
//拷贝到机子中
adb push /home/wangchuang/project/e0004h/OUT_APP/BjevAirConditioner-release-signed.apk /system/app/BjevAirConditioner-release-signed
//安装
pm install -r /system/app/BjevAirConditioner-release-signed/BjevAirConditioner-release-signed.apk
//运行
am start -n com.pateo.bjev.airconditioner/.activity.AirconditionActivity

PCAN 信号   ECC_0x4E0,1,2 FHS_GENERAL_STRTUS

---------------------- 语音记事本 打包 运行------------------
//打包
./build.sh -r BjevAudioNote/app;adb install -r ../OUT_APP/BjevAudioNote-release-signed.apk
//拷贝到机子中
adb push /home/wangchuang/project/e0004h/OUT_APP/BjevAudioNote-release-signed.apk /system/app/BjevAudioNote-release-signed
//安装
pm install -r /system/app/BjevAudioNote-release-signed/BjevAudioNote-release-signed.apk
//运行  随便
am start -n com.pateo.bjev.audionote/.activity.AudioNoteMainActivity


---------------------- 应用商店 打包 运行------------------
//打包
./build.sh -r BjevAppStore/app;adb install -r ../OUT_APP/BjevAppStore-release-signed.apk
//拷贝到机子中
adb push /home/wangchuang/project/e0004h/OUT_APP/BjevAppStore-release-signed.apk /system/app/BjevAppStore-release-signed
//安装
pm install -r /system/app/BjevAppStore-release-signed/BjevAppStore-release-signed.apk
//运行  随便
am start -n com.pateo.bjev.appstore.bjevappstore/com.pateo.bjev.appstore.bjevappstore.HomeActivity

adb shell dumpsys package com.pateo.bjev.violation | findstr versionCode


---------------------- 车况 打包 运行------------------
//打包
./build.sh -r BjevVehicle/app;adb install -r ../OUT_APP/BjevVehicle-release-signed.apk
//拷贝到机子中
adb push /home/wangchuang/project/e0004h/OUT_APP/BjevVehicle-release-signed.apk /system/app/BjevVehicle-release-signed
//安装
pm install -r /system/app/BjevVehicle-release-signed/BjevVehicle-release-signed.apk
//运行  随便
am start -n com.pateo.bjev.bjevvehicle/.HomeActivity

PCAN 信号 BCM_0x660,BMS_0x6c0 MCU_0x631  BCM_0x4A0

---------------------- 电台 打包 运行------------------
//打包
./build.sh -r BjevRadio/app;adb install -r ../OUT_APP/BjevRadio-release-signed.apk
//拷贝到机子中
adb push /home/wangchuang/project/e0004h/OUT_APP/BjevRadio-release-signed.apk /system/app/BjevRadio-release-signed
//安装
pm install -r /system/app/BjevRadio-release-signed/BjevRadio-release-signed.apk
//运行  随便
am start -n com.pateo.bjev.radio/.activity.RadioMainActivity

---------------------- 航旅 打包 运行------------------
//打包
./build.sh -r BjevAirTripService/app;adb install -r ../OUT_APP/BjevAirTripService-release-signed.apk
//拷贝到机子中
adb push /home/wangchuang/project/e0004h/OUT_APP/BjevAirTripService-release-signed.apk /system/app/BjevAirTripService-release-signed
//安装
pm install -r /system/app/BjevAirTripService-release-signed/BjevAirTripService-release-signed.apk
//运行  随便
am start -n com.qinggan.airtrip/.ui.activity.MainActivity


adb push /home/wangchuang/project/e0004h/OUT_APP/BjevLauncher-release-signed.apk /system/app/BjevLauncher-release-signed

pm install -r /system/app/BjevLauncher-release-signed/BjevLauncher-release-signed.apk

删除进程
获取进程id
ps |grep airconditioner

ps |grep launcher

ps |grep audionote

ps |grep bjevappstore

ps |grep bjevvehicle

ps |grep radio

杀死进程 8136进程id
kill 8136

// 删除数据库
rm -rf ./* */

// 拷贝 /storage/0C27-1940 == u盘名称 pro = 文件名全称
// 王闯 5457-A647
// 拷贝有两种方式 一种是进入文件需要拷贝的目的地
cp /storage/5457-A647/procrank .  // 这里的点代表当前路径

cp /storage/5457-A647/libpagemap.so .

cp /storage/4C6288224F082306/app_launch.xml .

// 另一种方式 拷贝的文件 + 目的地路径
cp /storage/5457-A647/procrank /system/bin/  // “/system/bin/” 就是目的地路径

// 为文件赋予权限 777 最高
chmod 777 /system/etc/qinggan/app_launch.xml

// 查看文件修改时间
ls -l

// 内存泄露
monkey -p com.pateo.bjev.bjevvehicle -p com.pateo.bjev.usercenter --hprof --ignore-crashes --ignore-timeouts --throttle 1000 --pct-touch 60 --pct-motion 40 50000000&

procrank | grep com.pateo.bjev.bjevvehicle

monkey -p com.pateo.bjev.audionote -p com.qinggan.carlifeapp --hprof --ignore-crashes --ignore-timeouts --throttle 1000 --pct-touch 60 --pct-motion 40 50000000&

procrank | grep com.pateo.bjev.audionote

procrank | grep com.pateo.bjev.appstore.bjevappstore

ps -t 2641 | busybox wc -c  // 查线程是否泄露技巧

































