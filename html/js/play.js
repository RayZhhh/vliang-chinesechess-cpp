/*! 一叶孤舟 | qq:28701884 | 欢迎指教 */

var play = play || {};

play.init = function () {

    play.my = 1;				//玩家方
    play.map = com.arr2Clone(com.initMap);		//初始化棋盘
    play.nowManKey = false;			//现在要操作的棋子
    play.pace = [];				//记录每一步
    play.isPlay = true;			//是否能走棋
    play.mans = com.mans;
    play.bylaw = com.bylaw;
    play.show = com.show;
    play.showPane = com.showPane;
    play.isOffensive = true;			//是否先手
    play.depth = play.depth || 3;				//搜索深度

    play.isFoul = false;	//是否犯规长将


    com.pane.isShow = false;			//隐藏方块

    //初始化棋子
    for (var i = 0; i < play.map.length; i++) {
        for (var n = 0; n < play.map[i].length; n++) {
            var key = play.map[i][n];
            if (key) {
                com.mans[key].x = n;
                com.mans[key].y = i;
                com.mans[key].isShow = true;
            }
        }
    }
    play.show();

    //绑定点击事件
    com.canvas.addEventListener("click", play.clickCanvas)


    com.get("regretBn").addEventListener("click", function (e) {
        play.regret();
    })
}


//悔棋
play.regret = function () {
    var map = com.arr2Clone(com.initMap);
    //初始化所有棋子
    for (var i = 0; i < map.length; i++) {
        for (var n = 0; n < map[i].length; n++) {
            var key = map[i][n];
            if (key) {
                com.mans[key].x = n;
                com.mans[key].y = i;
                com.mans[key].isShow = true;
            }
        }
    }
    var pace = play.pace;
    pace.pop();
    pace.pop();

    for (var i = 0; i < pace.length; i++) {
        var p = pace[i].split("")
        var x = parseInt(p[0], 10);
        var y = parseInt(p[1], 10);
        var newX = parseInt(p[2], 10);
        var newY = parseInt(p[3], 10);
        var key = map[y][x];
        //try{

        var cMan = map[newY][newX];
        if (cMan) com.mans[map[newY][newX]].isShow = false;
        com.mans[key].x = newX;
        com.mans[key].y = newY;
        map[newY][newX] = key;
        delete map[y][x];
        if (i == pace.length - 1) {
            com.showPane(newX, newY, x, y)
        }
        //} catch (e){
        //	com.show()
        //	z([key,p,pace,map])

        //	}
    }
    play.map = map;
    play.my = 1;
    play.isPlay = true;
    com.show();
}


//点击棋盘事件
play.clickCanvas = function (e) {
    if (!play.isPlay) return false;
    var key = play.getClickMan(e);
    var point = play.getClickPoint(e);

    var x = point.x;
    var y = point.y;

    if (key) {
        play.clickMan(key, x, y);
    } else {
        play.clickPoint(x, y);
    }
    play.isFoul = play.checkFoul();//检测是不是长将
}


//点击棋子，两种情况，选中或者吃子
play.clickMan = function (key, x, y) {
    var man = com.mans[key];
    //吃子
    if (play.nowManKey && play.nowManKey != key && man.my != com.mans[play.nowManKey].my) {
        //man为被吃掉的棋子
        if (play.indexOfPs(com.mans[play.nowManKey].ps, [x, y])) {
            man.isShow = false;
            var pace = com.mans[play.nowManKey].x + "" + com.mans[play.nowManKey].y
            //z(bill.createMove(play.map,man.x,man.y,x,y))
            delete play.map[com.mans[play.nowManKey].y][com.mans[play.nowManKey].x];
            play.map[y][x] = play.nowManKey;
            com.showPane(com.mans[play.nowManKey].x, com.mans[play.nowManKey].y, x, y)
            com.mans[play.nowManKey].x = x;
            com.mans[play.nowManKey].y = y;
            com.mans[play.nowManKey].alpha = 1

            play.pace.push(pace + x + y);
            play.nowManKey = false;
            com.pane.isShow = false;
            com.dot.dots = [];
            com.show()
            com.get("clickAudio").play();
            setTimeout("play.AIPlay()", 500);
            if (key == "j0") play.showWin(-1);
            if (key == "J0") play.showWin(1);
        }
        // 选中棋子
    } else {
        if (man.my === 1) {
            if (com.mans[play.nowManKey]) com.mans[play.nowManKey].alpha = 1;
            man.alpha = 0.6;
            com.pane.isShow = false;
            play.nowManKey = key;
            com.mans[key].ps = com.mans[key].bl(); //获得所有能着点
            com.dot.dots = com.mans[key].ps
            com.show();
            //com.get("selectAudio").start(0);
            com.get("selectAudio").play();
        }
    }
}

//点击着点
play.clickPoint = function (x, y) {
    var key = play.nowManKey;
    var man = com.mans[key];
    if (play.nowManKey) {
        if (play.indexOfPs(com.mans[key].ps, [x, y])) {
            var pace = man.x + "" + man.y
            //z(bill.createMove(play.map,man.x,man.y,x,y))
            delete play.map[man.y][man.x];
            play.map[y][x] = key;
            com.showPane(man.x, man.y, x, y)
            man.x = x;
            man.y = y;
            man.alpha = 1;
            play.pace.push(pace + x + y);
            play.nowManKey = false;
            com.dot.dots = [];
            com.show();
            com.get("clickAudio").play();
            setTimeout("play.AIPlay()", 500);
        } else {
            //alert("不能这么走哦！")
        }
    }
}


//Ai自动走棋
play.AIPlay = function () {
    //return
    // TODO ziri----将棋盘信息发送到本地服务器
    //
    play.my = -1;
    //var pace = AI.init(play.pace.join(""))
    var pace = [];
    // [ '1' , '0' , '2' , '2 ']
    // 服务器的对应坐标是 0，1，2，2，解析的时候需要注意
    // ----------------------------------------------------------------
    // 棋盘信息，发送给服务器
    let chessboardMessage = '';
    var tmap = com.arr2Clone(play.map);
    for (let i = 0; i < 10; i++) {
        for (let j = 0; j < 9; j++) {
            tmap[i][j] = play.map[9 - i][8 - j];
        }
    }
    for (let i = 0; i < 10; i++) {
        for (let j = 0; j < 9; j++) {
            if (tmap[i][j] == 'c0' || tmap[i][j] == 'c1') {
                chessboardMessage += '-1';
            } else if (tmap[i][j] == 'C0' || tmap[i][j] == 'C1') {
                chessboardMessage += '1';
            } else if (tmap[i][j] == 'm0' || tmap[i][j] == 'm1') {
                chessboardMessage += '-2';
            } else if (tmap[i][j] == 'M0' || tmap[i][j] == 'M1') {
                chessboardMessage += '2';
            } else if (tmap[i][j] == 'x0' || tmap[i][j] == 'x1') {
                chessboardMessage += '-3';
            } else if (tmap[i][j] == 'X0' || tmap[i][j] == 'X1') {
                chessboardMessage += '3';
            } else if (tmap[i][j] == 's0' || tmap[i][j] == 's1') {
                chessboardMessage += '-4';
            } else if (tmap[i][j] == 'S0' || tmap[i][j] == 'S1') {
                chessboardMessage += '4';
            } else if (tmap[i][j] == 'j0') {
                chessboardMessage += '-5';
            } else if (tmap[i][j] == 'J0') {
                chessboardMessage += '5';
            } else if (tmap[i][j] == 'p0' || tmap[i][j] == 'p1') {
                chessboardMessage += '-6';
            } else if (tmap[i][j] == 'P0' || tmap[i][j] == 'P1') {
                chessboardMessage += '6';
            } else if (tmap[i][j] == 'z0' || tmap[i][j] == 'z1' || tmap[i][j] == 'z2' || tmap[i][j] == 'z3' || tmap[i][j] == 'z4') {
                chessboardMessage += '-7';
            } else if (tmap[i][j] == 'Z0' || tmap[i][j] == 'Z1' || tmap[i][j] == 'Z2' || tmap[i][j] == 'Z3' || tmap[i][j] == 'Z4') {
                chessboardMessage += '7';
            } else {
                chessboardMessage += '0';
            }
            if (i != 9 || j != 8) {
                chessboardMessage += ';';
            }
        }
    }
    console.log(chessboardMessage);
    // 发送http请求到服务器
    let url = "http://127.0.0.1:8080";
    var request = new XMLHttpRequest();
    request.open('POST', url, true);
    request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    // request.send("chessboard=" + chessboardMessage);
    let json = "{ \"" + "chessboard" + "\":\"" + chessboardMessage + "\"}";
    console.log(json)
    request.send(json);

    // 获取服务器响应
    var responseResult = "";
    request.onreadystatechange = function () {
        if (request.readyState === 4) {
            if (request.status === 200) {
                responseResult = request.responseText;
                console.log('response result: ' + responseResult);
                // 解析棋盘信息
                var respArr = responseResult.split(";");
                let fromX = 8 - respArr[1];
                let fromY = 9 - respArr[0];
                let toX = 8 - respArr[3];
                let toY = 9 - respArr[2];
                var pace = [fromX, fromY, toX, toY];
                console.log(pace)
                if (!pace) {
                    play.showWin(1);
                    return;
                }
                play.pace.push(pace.join(""));
                var key = play.map[pace[1]][pace[0]]
                play.nowManKey = key;

                var key = play.map[pace[3]][pace[2]];
                if (key) {
                    play.AIclickMan(key, pace[2], pace[3]);
                } else {
                    play.AIclickPoint(pace[2], pace[3]);
                }
                //com.get("clickAudio").play();
            }
        }
    }
    // ----------------------------------------------------------------
}


//检查是否长将
play.checkFoul = function () {
    var p = play.pace;
    var len = parseInt(p.length, 10);
    if (len > 11 && p[len - 1] == p[len - 5] && p[len - 5] == p[len - 9]) {
        return p[len - 4].split("");
    }
    return false;
}


play.AIclickMan = function (key, x, y) {
    var man = com.mans[key];
    //吃子
    man.isShow = false;
    delete play.map[com.mans[play.nowManKey].y][com.mans[play.nowManKey].x];
    play.map[y][x] = play.nowManKey;
    play.showPane(com.mans[play.nowManKey].x, com.mans[play.nowManKey].y, x, y)

    com.mans[play.nowManKey].x = x;
    com.mans[play.nowManKey].y = y;
    play.nowManKey = false;

    com.show()
    if (key == "j0") play.showWin(-1);
    if (key == "J0") play.showWin(1);
}

play.AIclickPoint = function (x, y) {
    var key = play.nowManKey;
    var man = com.mans[key];
    if (play.nowManKey) {
        delete play.map[com.mans[play.nowManKey].y][com.mans[play.nowManKey].x];
        play.map[y][x] = key;

        com.showPane(man.x, man.y, x, y)


        man.x = x;
        man.y = y;
        play.nowManKey = false;

    }
    com.show();
}


play.indexOfPs = function (ps, xy) {
    for (var i = 0; i < ps.length; i++) {
        if (ps[i][0] == xy[0] && ps[i][1] == xy[1]) return true;
    }
    return false;

}

//获得点击的着点
play.getClickPoint = function (e) {
    var domXY = com.getDomXY(com.canvas);
    var x = Math.round((e.pageX - domXY.x - com.pointStartX - 20) / com.spaceX)
    var y = Math.round((e.pageY - domXY.y - com.pointStartY - 20) / com.spaceY)
    return {"x": x, "y": y}
}

//获得棋子
play.getClickMan = function (e) {
    var clickXY = play.getClickPoint(e);
    var x = clickXY.x;
    var y = clickXY.y;
    if (x < 0 || x > 8 || y < 0 || y > 9) return false;
    return (play.map[y][x] && play.map[y][x] != "0") ? play.map[y][x] : false;
}

play.showWin = function (my) {
    play.isPlay = false;
    if (my === 1) {
        alert("恭喜你，你赢了！");
    } else {
        alert("很遗憾，你输了！");
    }
}
