# Spine 动态立绘 Web 播放器

这是一个功能丰富的 Web 前端项目模板，用于展示使用 [Spine](http://zh.esotericsoftware.com/) 制作的 2D 角色动态立绘。该项目不仅能播放骨骼动画，还集成了复杂的交互逻辑、背景音乐和多通道语音系统，旨在提供一个生动、沉浸式的角色展示体验。

本项目可以直接在本地运行，也可轻松部署到任何静态网页服务器。

## ✨ 主要功能

*   **Spine 动画播放**: 基于 Spine Runtimes 3.8 版本，稳定高效地渲染 `.skel` 骨骼动画。
*   **复杂的状态机**:
    *   **加载/启动**: 页面打开时播放一次性的 `Start` 动画。
    *   **待机**: 默认状态下循环播放 `Idle` 动画。
    *   **交互**: 鼠标点击时触发 `Interact` 动画。
    *   **特殊/闲置**: 用户长时间无操作后，随机触发 `Special` 动画，增加趣味性。
*   **多通道音频系统**:
    *   **背景音乐**: 循环播放背景音乐（BGM），且不受角色语音影响。
    *   **角色语音**: 语音与特定动作精准同步，且拥有独立的播放通道。
    *   **随机语音**: 交互语音可从多个文件中随机选择一个播放。
    *   **防打扰机制**: 快速连续点击时，不会打断正在播放的语音，避免声音混乱。
*   **零依赖本地运行**: 无需复杂的环境配置，仅需一个简单的本地 HTTP 服务器即可完美运行。
*   **UI控件和配置本地存储**: 网页底部自带UI控件，可随你所欲切换方舟不同主题的背景和背景音乐，还可以调整角色的位置。选一组你最喜欢的配置，手动将其写入`config.json`中吧！
*   **Wallpaper Engine适配**: 此页面在Windows平台做壁纸时，底部UI控件常态下会被任务栏遮住，你可以先在**隐藏任务栏**的条件下做好调整再写入json文件。

## 🛠️ 制作过程

简单说一下制作过程。AI+官方文档足以解决绝大多数问题了。

1.  **在prts.wiki平台网络抓包**:
    - 找一个有动态立绘且prts上上传了TA的动态立绘的角色，比如W的“恍惚”。
    - F12（Fn+F12）打开开发者工具，并找到**网络**。
    - 点击右侧**动态立绘**，此时可以监听到**一个后缀为skel的纯文本文件**、**一个后缀为atlas的非纯文本文件**、**一张显然是wife碎片的png图片**、**一张显然是背景的png图片**。有这四个其实就够了。

2.  **编写代码**:
    - 需要先找到**3.8**版本的`spine web player`依赖文件，这次就只需要`spine-player.js`和`spine-player.css`两个文件就够了。（真是让我一顿好找
    - 将这两个依赖文件和刚刚抓包抓到的四个文件放入同一个文件夹，再新建一个`index.html`文件。
    - html中编写如下代码：
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
3.  **更多交互**:
    - 到上一步其实就差不多了，如果你想要更多效果，可以去看spine官网或问AI。


## 🔧 技术栈

*   **HTML5**
*   **CSS3**
*   **JavaScript (ES6)**
*   **Spine Runtimes for web (v3.8)**

## 致谢

*   感谢 [鹰角网络](https://ak.hypergryph.com/) 美术组的优秀作品，立绘精美，声优大牌。（bushi
*   感谢 [prts.wiki](https://prts.wiki/) 多年用爱发电，将解包获取的游戏资源文件无偿分享到网站上。

*   感谢 [Esoteric Software](https://esotericsoftware.com/) 开发了强大的 Spine 动画工具及其 Web 播放器。