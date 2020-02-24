git commit -m "提交内容"
备注:DOING=#E0004H-7 需要独占一行

//代码提交到版本库  e0004h分支
git push origin HEAD:refs/for/b1031h

git push origin HEAD:refs/for/b1031h_sop

git push origin HEAD:refs/for/c3005s

git push origin HEAD:refs/for/e0004h

git pull --rebase

//修改已经提交的代码 重新提交
git commit --amend

//  git 回滚
git reset --hard 0d65300cdb4b59265e1b0bb241b8f0e4207b38c7
git pull // 拉去最新pull

// 复原
git checkout .

// 看看分支
git branch 

// 切换分支aaa
git checkout aaa 

// 创建aaa分支
git branck aaa 

// 本地创建 aaa分支，同时切换到aaa分支。只有提交的时候才会在服务端上创建一个分支
git checkout -b aaa 

// 将命令打印到文件中
history  > /home/wangchuang/1.txt

// 抓取log
adb logcat -v time > /home/wangchuang/1.log

查看log日志的命令：
grep -nr "关键字" 
logcat |grep "关键字"

--------邮件格式-------
Hi，温丽斌：

CheckList中对应模块已自测完成，表格已完善，请查收！

BR（or Best Regards），

王闯

--------------------------------------------------------
git commit -m "DOING=#B1030H-1366
【音乐】切歌时列表自动显示跳转到当前播放的歌曲上"

原因分析
服务端响应太快，导致app处理不过来

解决方案
handle消息处理重新整理

影响模块
电台"


git commit -m "DOING=#C3005S-211
【空调】手机端空调第一次提交"



















