
ps -ef |grep hikka | grep -v grep | awk '{print $2}' | xargs -r kill -9
nohup ./hikka > hikka.out 2>&1 &
ps -ef | grep hikka 


# cd rtsp-server
# ps -ef |grep rtsp-server-linux | grep -v grep | awk '{print $2}' | xargs -r kill -9
# nohup ./hikka > hikka.out 2>&1 &
# ps -ef | grep hikka 
