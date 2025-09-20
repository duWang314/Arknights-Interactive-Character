# 基于 Spine Web Player 的纯前端明日方舟角色动态立绘壁纸

这是一个功能丰富的 Web 前端项目，用于展示使用 [Spine](http://zh.esotericsoftware.com/) 制作的 2D 角色动态立绘。该项目不仅能播放骨骼动画，还集成了复杂的交互逻辑、背景音乐和多通道语音系统，旨在提供一个生动、沉浸式的角色展示体验。

本项目可以直接在本地运行，也可轻松部署到任何静态网页服务器。

## 👁️ 效果预览（静态）
<img alt="preview_令_崖高梦远" src="https://github.com/user-attachments/assets/4e03acd7-b535-4642-9d14-517f9609656e" />
<br>
<br>
<img alt="preview_银灰_不融冰" src="https://github.com/user-attachments/assets/31c98532-7508-45d8-8f74-8292cd444698" />
<br>
<br>
<img alt="preview_死芒_夏卉" src="https://github.com/user-attachments/assets/ad37825e-02c7-4d22-bbda-22d5f32f1a00" />

## 🔗创意工坊链接

*   **令_崖高梦远**:
    *   https://steamcommunity.com/sharedfiles/filedetails/?id=3570156349
*   **银灰_不融冰**:
    *   https://steamcommunity.com/sharedfiles/filedetails/?id=3569204392
*   **死芒_夏卉**:
    *   https://steamcommunity.com/sharedfiles/filedetails/?id=3568470654
*   **水月_夏日餮宴**:
    *   https://steamcommunity.com/sharedfiles/filedetails/?id=3566064566
*   **史尔特尔_缤纷奇境**:
    *   https://steamcommunity.com/sharedfiles/filedetails/?id=3563840882
*   **W_恍惚**:
    *   https://steamcommunity.com/sharedfiles/filedetails/?id=3563835238

## ✨ 主要功能

*   **Spine 动画播放**: 基于 Spine Runtimes 3.8 版本，这也是明日方舟当前使用的版本。
*   **复杂的状态机**:
    *   **加载/启动**: 页面打开时播放一次性的 `Start` 动画（如果有）。
    *   **待机**: 默认状态下循环播放 `Idle` 动画。
    *   **交互**: 鼠标点击时触发 `Interact` 动画。
    *   **特殊/闲置**: 用户长时间无操作后，随机触发 `Special` 动画，增加趣味性。
*   **多通道音频系统**:
    *   **背景音乐**: 循环播放背景音乐（BGM），且不受角色语音影响。
    *   **角色语音**: 语音与特定动作精准同步，且拥有独立的播放通道。
    *   **随机语音**: 交互语音可从多个文件中随机选择一个播放。
    *   **防打扰机制**: 快速连续点击时，不会打断正在播放的语音，避免声音混乱。
*   **零依赖本地运行**: 无需复杂的环境配置，双击`index.html`即可运行。推荐使用Wallpaper Engine运行，以确保能够读取到配置文件，还能享受更高的清晰度。在浏览器运行时，使用"Ctrl" + "-"可以显著提高页面清晰度，但相应的电脑资源的占用也会变高。
*   **UI控件和配置本地存储**: 网页自带UI控件，可随你所欲切换方舟不同主题的背景和背景音乐，还可以调整角色的位置和大小。选一组你最喜欢的配置，手动将其写入`config.json`中吧！

## ❗使用说明及注意事项

*   **如果使用浏览器打开**:
    *   **双击`index.html`**: 由于浏览器的安全限制，将无法读取`config.json`。要修改配置只能改html文件了。
    *   **本地或托管的服务器**: 可以正常读取`config.json`。
*   **如果使用Wallpaper Engine打开，则可以读取配置文件**:
    *   **只需要注意**: 音乐和问候语音自动播放，不要被吓到了。

## 🛠️ 制作过程

简单说一下制作过程。AI+[官方文档（旧）](https://zh.esotericsoftware.com/blog/Embedding-assets-with-Spine-Web-Player)+[官方文档（新）](https://zh.esotericsoftware.com/spine-player)足以解决绝大多数问题了。

1.  **资源获取 - 法一：在[prts.wiki](https://prts.wiki/w/%E5%B9%B2%E5%91%98%E4%B8%80%E8%A7%88)平台网络抓包**:
    - 找一个有动态立绘且prts上上传了TA的动态立绘的角色，比如[W](https://prts.wiki/w/W)的“恍惚”。
    - F12（Fn+F12）打开开发者工具，并找到**网络**。
    - 点击右侧**动态立绘**，此时可以监听到**一个后缀为skel的纯文本文件**、**一个后缀为atlas的非纯文本文件**、**一张或是多张显然是wife碎片的png图片**、**一张显然是背景的png图片**，双击就可以下载，将这三样文件保存到本地。
    - 至此你完成了网络抓包形式的资源获取，它相对简单，但只能获取较早期发布的动态立绘。要想获取当期的动态立绘，请参考**资源获取 - 法二：自己解包**。

2.  **资源获取 - 法二：自己解包**:
    - 前往[明日方舟中国服官网](https://ak.hypergryph.com/downloads/android_lastest)下载 apk 安装包。
    - [Harry Huang](https://github.com/isHarryh) 大佬使用 Python 制作并开源了一个自动化解包[脚本](https://github.com/isHarryh/Ark-Unpacker)，参考他仓库下的 README 文件，合并两个 Android 文件夹获取完整资源。
    - 动态立绘的目录在 Android -> arts -> dynchars 路径下，将 dynchars 这个文件夹与 release 中 ArkUnpacker 这个可执行文件放在同一个文件夹下，为了方便“一键执行”，此时当前文件夹中只能有 dynchars 这一个文件夹。
    - 双击 ArkUnpacker，选择第一个选项“一键执行”。等待数分钟得到解包结果，请确保你的设备硬盘和 CPU 的性能达标。你需要在很多张图片里找到立绘的背景图片。这里的解包结果我们只要立绘中的背景，wife 碎片我们将采取另一种方式解包得到，因为使用这种方式解出来的 wife 碎片会更“亮”一些，导致你的人物看起来像幽灵。
    - 再次来到 ArkUnpacker 的命令行主界面，这次我们选择第五个选项“自定义Spine模型导出”，这里你就需要手动复制解包文件夹和输出文件夹的路径了。经过这次解包，我们就能获取无损的 wife 碎片。
    - 不过，解包出来的一系列文件夹的名称对我们来说会有些陌生，我总结了一些规律，可以根据文件夹名称的后半部分来快速识别是哪个干员。
    
    ```txt
    文件夹名称大致如下：
    char_003_kalts_boc#6
    
    将其分为三个部分：
    char_003 -> (1)
    kalts -> (2)
    boc#6 -> (3)
    
    各个部分的含义：
    (1): character 003 号，含义不是很明确。
    (2): kalts，表示这个干员的名字，不过凯尔希的完整英文名应该是Kal'tsit。虽然此处你有很大概率可以猜出这就是凯尔希，但更多文件夹此部分不容易看出。
    (3): boc#6，表示这个皮肤属于“斗争血脉”（bloodline of combat）系列，且所属的具体时装组为“斗争血脉/VI”，此时再去查看碎片，不难猜出这就是 凯尔希_残余 的动态立绘。我认为通过这一部分判断是最有把握的。以下给出皮肤系列总结。
    
    动态皮肤系列总结：
    sale - 忒斯特收藏
    epoque - 时代
    nian - 0011制造
    summer - 珊瑚海岸
    witch - 巫异盛宴
    wild - 生命之地
    boc - 斗争血脉
    ambience synesthesia - 音律联觉
    ncg - 合作款
    iteration - 命途迭代
    sightseer - 错位巡礼
    cfa - 中国电影资料馆
    ncg - 国家地理
    
    其他系列（截至2025.9.20未发布动态皮肤）：
    whirlwind - 0011飙系列
    yun - 0011韵系列
    marthe - 玛尔特
    winter - 寒武纪系列
    snow - 冰原信使
    sweep - 雷神开拓者
    striker - 雷神推进者
    kitchen - 罗德厨房
    ghost - 缠梦古堡
    race - 啸风
    shining - 闪耀阶梯
    game - 成就之星
    unveiling - 待予花冠
    kfc - 肯德基
    it - i.t
    taiko - 太鼓之达人
    wwf - WWF
    ```
    
    
    
3.  **编写代码**:
    
    - 需要先找到**3.8**版本的`spine web player`依赖文件，这次就只需要`spine-player.js`和`spine-player.css`两个文件就够了。
    - 将这两个依赖文件和刚刚获取的资源文件放入同一个文件夹，再新建一个`index.html`文件。
    - html 中编写如下代码：
```html
<script src="./spine-player.js"></script>
<link rel="stylesheet" href="./spine-player.css">

<div id="player"></div>

<script>
new spine.SpinePlayer("player", {
 skelUrl: "./<刚刚抓到的skel文件>",
 atlasUrl: "./<刚刚抓到的atlas文件>",
 animation: "Idle",
});
</script>
```
4.  **壁纸运行**:
    - **浏览器运行的问题：** 编写完了上述代码，保存然后双击`index.html`打开网页，您可能发现页面中只有一个不停旋转的 spine 加载图标。当您按下 F12 查看控制台输出信息时就会发现，刚刚 html 中的 js 脚本获取 skel, atlas, png 文件的过程其实是 **失败** 的，这是因为浏览器通常会有安全策略，不允许 js 脚本读取本地文件。
    - **Wallpaper Engine中运行：** 不修改代码，在Wallpaper Engine中尝试运行（打开壁纸 -> 打开离线壁纸（动态） -> 找到`index.html`）就会发现可以运行，动态小人正常地显示了出来。这是因为Wallpaper Engine毕竟不是浏览器，只是有一个Chromium内核，所以Wallpaper Engine并没有常见浏览器的安全策略。这也是为什么你上网冲浪时电脑通常没那么容易中病毒，而在Wallpaper Engine中订阅网页类壁纸却要小心慎重的原因之一。
    - **浏览器运行的解决方案 - 服务器启动：** 浏览器的安全策略读取不允许 js 脚本读取本地文件，但 js 发送 http 请求接收网络文件则是可以的。你可以将你的 skel, atlas, png 文件托管到网络平台，然后在 js 脚本中以网页链接的形式引用这些文件。或者，不修改代码，使用本地服务器诸如`python -m http.server 8080`的方式启动也是完全可以的。您可以参考 test 文件夹下的 `start server.bat`，里面提供了一键启动服务器并使用 edge 浏览器访问的快捷通道。
    - **浏览器运行的解决方案 - 内嵌资源：** 在[官方文档（旧）](https://zh.esotericsoftware.com/blog/Embedding-assets-with-Spine-Web-Player)和[官方文档（新）](https://zh.esotericsoftware.com/spine-player)中都提到了如何将原生资源内嵌到 js 脚本中，具体到 Windows 平台，你可以用 Windows 自带的 certutil (certificate util) 来进行编码：`certutil -encode example.png png.txt`对于 `png.txt` ，你还需要去除首位行中像“-----BEGIN CERTIFICATE-----”这样的段，以及文件中 **所有** 的换行符。去除换行符的操作如果用 VS Code 中"Change All Occurrences"的功能，可能会导致 VS Code 卡顿。这里推荐使用 test/utils 下的 C 语言工具 b64encode ，输入`b64encode example.png`即可一步到位，快速将 Mb 级别的文件完成编码，将仅一行的结果写入`example.png_output`文本文件中。

## 🔧 技术栈

*   **HTML5**
*   **CSS3**
*   **JavaScript (ES6)**
*   **Spine Runtimes for web (v3.8)**

## 致谢

*   感谢 [鹰角网络](https://ak.hypergryph.com/) 美术组的优秀作品，立绘精美，声优大牌。（bushi
*   感谢 [prts.wiki](https://prts.wiki/) 多年用爱发电，将解包获取的游戏资源文件无偿分享到网站上。
*   感谢 [Harry Huang](https://github.com/isHarryh) 大佬做的自动化解包[脚本](https://github.com/isHarryh/Ark-Unpacker)。
*   感谢 [Esoteric Software](https://esotericsoftware.com/) 开发了强大的 Spine 动画工具及其 Web 播放器。
