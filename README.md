# color_blind_detection_system
基于Qt的色盲检测系统
## 运行方法
- 如果是要下到开发板上的话，直接把build目录的项目文件传到开发板上就可以直接运行
- 在Qt上运行的话，直接下载源码，在Qt上可以直接运行
运行时，点击下一张/上一张可以切换图片，右侧可以选择答案，答完题后可以点击获取结果得到分数
也可以通过手指滑动的方式切换图片，只需在图片区域进行滑动即可
当为第一道题时，再次点击上一张，会提示是第一张图片
当为最后一道题时，再次点击下一张，会提示已经是最后一张图片
如果还没有答完题就获取结果，会提示需答完全部题目才能获得分数
答完的题会被自动记录，当答完后再返回来时是会自己选中之前答过的选项
## 运行图片
![image](https://user-images.githubusercontent.com/75490362/124133999-f4be1b00-dab4-11eb-8aab-8e94c05334cd.png)
![image](https://user-images.githubusercontent.com/75490362/124135096-110e8780-dab6-11eb-8ab1-e6ae6d288eab.png)
![image](https://user-images.githubusercontent.com/75490362/124135136-1d92e000-dab6-11eb-9428-77abb8fd84fd.png)
![image](https://user-images.githubusercontent.com/75490362/124135161-25528480-dab6-11eb-87c0-82b1a826dc08.png)
![image](https://user-images.githubusercontent.com/75490362/124135264-3b604500-dab6-11eb-9279-1603dab4651d.png)
## 注意事项
- 图片目录是images，想加图片可以自己加，添加好图片后，需要修改源码
保存用户结果的数组，需要修改为题目的个数
QString results[15]
保存图片路径的数组，需要添加新加进来的图片的路径，并修改数组大小
QString images[15] 
保存答案的数组，需要添加新加进来的图片的答案，并修改大小
QString answer[15][3]
