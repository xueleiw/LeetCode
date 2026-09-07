# LeetCode

# 取消全局代理设置
git config --global --unset http.proxy
git config --global --unset https.proxy

# 查看当前的代理设置
git config --global --get http.proxy
git config --global --get https.proxy

# 设置系统代理
git config --global http.proxy http://127.0.0.1:7890