//============
//Webpage Code
//============
String webpageCode = R"***(
<!DOCTYPE html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title> Inkubator Web Server </title>
</head>
<html>
<!----------------------------CSS---------------------------->
<style>
    body {background-color: rgba(128, 128, 128, 0.884)}
    h4 {font-family: arial; text-align: center; color: white;}
    table{
        width:100%
    }
    .start{
        background-color: green;
    }
    .stop{
        background-color: red;
    }
    .card
    {
        max-width: 650px;
        min-height: 100px;
        background: rgba(255, 0, 0, 0.521);
        padding: 10px;
        font-weight: bold;
        font: 25px calibri;
        text-align: center;
        box-sizing: border-box;
        color: blue;
        margin:20px;
        box-shadow: 0px 2px 15px 15px rgba(0,0,0,0.75);
    }
</style>
<!----------------------------HTML--------------------------->
<body>
<center>
<div class="card">
    <h1><span style="background-color:white">Incubator Web Server</span></h1>
    <table>
        <tr><td>Температура повітря:</td>
            <td><span style="color:yellow" id="Temp">0</span>С</td>
            <td><input type="number" value="40"></td>
            <td><input type="checkbox"></td>
        </tr>
        <tr>
            <td>Вологість повітря:</td>
            <td><span style="color:yellow" id="Humd">0</span>%</td>
            <td><input type="number" value="40"></td>
            <td><input type="checkbox"></td>
        </tr>
        <tr><td>Температура лівий дачик:</td>
            <td><span style="color:yellow" id="TempL">0</span>С</td>
            <td><input type="number" value="40"></td>
            <td><input type="checkbox"></td>
        </tr>
        <tr><td>Температура лоток:</td>
            <td><span style="color:yellow" id="TempC">0</span>С</td>
            <td><input type="number" value="40"></td>
            <td><input type="checkbox"></td>
        </tr>
        <tr><td>Температура правий дачик:</td>
            <td><span style="color:yellow" id="TempR">0</span>С</td>
            <td><input type="number" value="40"></td>
            <td><input type="checkbox"></td>
        </tr>
    </table>

    <button class="start" id="startHeating" onclick="startHeating()">Увімкнути нагрів</button>
    <button class="stop" id="startHeating" onclick="stopHeating()">Вимкнути нагрів</button>
    <button class="start" id="startPump" onclick="startPump()">Увімкнути Помпу</button>
    <button class="stop" id="stopPump" onclick="stopPump()">Вимкнути Помпу<</button>
</div>
<h4>
    <button onclick="help()">Help</button><br><br>
    <div id="myDIV"> </div>
</h4>
<!-------------------------JavaScrip------------------------->
<script>
    setInterval(function()
    {
        getTempCenter();
        getTempRight();
        getTempLeft();
        getTempTop();
        getHumd();
    }, 2000);
    //-------------------------------------------------------
    function startPump()
    {

      var startPumpRequest = new XMLHttpRequest();
      startPumpRequest.onreadystatechange = function()
      {
        if(this.readyState == 4 && this.status == 200)
        {
//          document.getElementById("TempC").innerHTML =
//          this.responseText;
        }
      };
      startPumpRequest.open("GET", "startPump", true);
      startPumpRequest.send();
    }
    //-------------------------------------------------------
    function stopPump()
    {

      var stopPumpRequest = new XMLHttpRequest();
      stopPumpRequest.onreadystatechange = function()
      {
        if(this.readyState == 4 && this.status == 200)
        {
//          document.getElementById("TempC").innerHTML =
//          this.responseText;
        }
      };
      stopPumpRequest.open("GET", "stopPump", true);
      stopPumpRequest.send();
    }
    //-------------------------------------------------------
    function stopHeating()
    {

        var stopHeatingRequest = new XMLHttpRequest();
        stopHeatingRequest.onreadystatechange = function()
        {
            if(this.readyState == 4 && this.status == 200)
            {
//          document.getElementById("TempC").innerHTML =
//          this.responseText;
            }
        };
        stopHeatingRequest.open("GET", "stopHeating", true);
        stopHeatingRequest.send();
    }
    //-------------------------------------------------------
    function startHeating()
    {

        var startHeatingRequest = new XMLHttpRequest();
        startHeatingRequest.onreadystatechange = function()
        {
            if(this.readyState == 4 && this.status == 200)
            {
//          document.getElementById("TempC").innerHTML =
//          this.responseText;
            }
        };
        startHeatingRequest.open("GET", "startHeating", true);
        startHeatingRequest.send();
    }
    //-------------------------------------------------------
    function startHeating()
    {

        var startHeatingRequest = new XMLHttpRequest();
        startHeatingRequest.onreadystatechange = function()
        {
            if(this.readyState == 4 && this.status == 200)
            {
                document.getElementById("TempC").innerHTML =
                    this.responseText;
            }
        };
        startHeatingRequest.open("GET", "startHeating", true);
        startHeatingRequest.send();
    }
    //-------------------------------------------------------
    function getTempCenter()
    {

        var getTempRequestCenter = new XMLHttpRequest();
        getTempRequestCenter.onreadystatechange = function()
        {
            if(this.readyState == 4 && this.status == 200)
            {
                document.getElementById("TempC").innerHTML =
                    this.responseText;
            }
        };
        getTempRequestCenter.open("GET", "getTempCenter", true);
        getTempRequestCenter.send();
    }
    //-------------------------------------------------------
    function getTempCenter()
    {

        var getTempRequestCenter = new XMLHttpRequest();
        getTempRequestCenter.onreadystatechange = function()
        {
            if(this.readyState == 4 && this.status == 200)
            {
                document.getElementById("TempC").innerHTML =
                    this.responseText;
            }
        };
        getTempRequestCenter.open("GET", "getTempCenter", true);
        getTempRequestCenter.send();
    }
    //-------------------------------------------------------
    function getTempRight()
    {

        var getTempRequestRight = new XMLHttpRequest();
        getTempRequestRight.onreadystatechange = function()
        {
            if(this.readyState == 4 && this.status == 200)
            {
                document.getElementById("TempR").innerHTML =
                    this.responseText;
            }
        };
        getTempRequestRight.open("GET", "getTempRight", true);
        getTempRequestRight.send();
    }
    //-------------------------------------------------------
    function getTempLeft()
    {

        var getTempRequestLeft = new XMLHttpRequest();
        getTempRequestLeft.onreadystatechange = function()
        {
            if(this.readyState == 4 && this.status == 200)
            {
                document.getElementById("TempL").innerHTML =
                    this.responseText;
            }
        };
        getTempRequestLeft.open("GET", "getTempLeft", true);
        getTempRequestLeft.send();
    }
    //-------------------------------------------------------
    function getTempTop()
    {
        var getTempRequest = new XMLHttpRequest();
        getTempRequest.onreadystatechange = function()
        {
            if(this.readyState == 4 && this.status == 200)
            {
                document.getElementById("Temp").innerHTML =
                    this.responseText;
            }
        };
        getTempRequest.open("GET", "getTempTop", true);
        getTempRequest.send();

    }
    //-------------------------------------------------------
    function getHumd()
    {
        var getHumdRequest = new XMLHttpRequest();
        getHumdRequest.onreadystatechange = function()
        {
            if(this.readyState == 4 && this.status == 200)
            {
                document.getElementById("Humd").innerHTML =
                    this.responseText;
            }
        };
        getHumdRequest.open("GET", "getHumd", true);
        getHumdRequest.send();
    }
    //-------------------------------------------------------
    function help()
    {
        var x = document.getElementById("myDIV");
        var message = "POT connected to ADC0 : 12-bit value (0 ---> 4095)";
        if (x.innerHTML == "") x.innerHTML = message;
        else x.innerHTML = "";
    }
</script>
</center>
</body>
</html>
)***";
