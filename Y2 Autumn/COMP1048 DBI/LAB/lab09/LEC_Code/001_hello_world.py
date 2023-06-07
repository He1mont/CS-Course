# Specify that we want to "use" the flask module in our Python application

# 第一部分：初始化，所有flask都必须创建程序实例
from flask import Flask
app = Flask(__name__)
    # This initializes the Flask instance to variable named app
    # We do not need to specify variable types in Python as it is dynamically typed

# 第二部分，路由(Route)和视图函数
# 客户端发送URL给web服务器，web服务器将URL转发给Flask程序实例
# 程序实例需要知道每一个URL请求启动哪一部分代码
# 所以保存了一个URL和Python函数的映射关系
# 处理URL和函数之间关系的程序叫做路由(Route)
# 在flask种，定义路由最简便的方式，是使用程序实例的app.route装饰器
# 把装饰的函数注册为路由

@app.route('/')
def hello_world():
    # Not the importance of indentation in Python code.
    return 'Hello DBI!'

# This will serve as the entry point for our program. 
# Here we tell Flask to run and specify that we want output from the 
# debugger and specify the specific port we want to access the service from. 

# 第三部分：程序实例用run方法启动flask集成的开发web服务器
# __name__ == '__main__'是python常用的方法

if __name__ == '__main__':
    app.debug = True
    # After this line executes, a long running Flask process will
    # "serve" our application, which will be accessible via:
    # http://localhost:5000 or http://127.0.0.1:5000 (on most systems)
    app.run(port=5000)

    # what's the difference between slide 13
