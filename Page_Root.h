
/* 
 *  TODO: You can't use libraries from the internet here if the client is directly connected to the ESP... 
 *  because then your client doesn't have access to the internet, now does it? Switch back to microAjax.
 */

const char PAGE_Root[] PROGMEM = R"=====(
<!doctype html>
<meta name="viewport" content="width=device-width, initial-scale=1" />
<script src="microajax.js"></script> 
<html>
  <head>
    <title>ESP8266 IOT Serial to Web</title>
    <style>
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }
    </style>
  <meta charset="utf-8" />
  </head>
  <body>
    <pre><div id='log'></div></pre>
    <p>
    <form id='msg' action='data' method='get'>
    <input id='txt' name='text' type='text'></input><input id='crlf' type='checkbox' checked>+crlf?</input>
    </form></p>
    <p><a href="/admin.html">Settings</a> <a href="/file?start=1">Stream</a></p>
    <script type='text/javascript' src='http://ajax.googleapis.com/ajax/libs/jquery/1.3/jquery.min.js'></script>
    <script type='text/javascript'>
$('#msg').submit(function(){ 
    var clientmsg = $('#txt').val();
    if ($('#crlf').is(':checked')) clientmsg+='\r';
    var log=$('#log');
    log.html(log.html()+'<b>'+clientmsg+'</b>');
    $.get('data', {text: clientmsg}, function(html){
        log.html(log.html()+html);
        });
    $('#txt').attr('value', '');
    loadLog(); //instantly pick up any response.
    return false;
  });
function loadLog(){
  var log=$('#log');
  $.ajax({
      url: 'data',
      cache: false,
      success: function(html){
        log.html(log.html()+html);
        },
    });
  };
 setInterval (loadLog, 2500);
      </script>
  </body>
</html>

)=====";

void handle_root(AsyncWebServerRequest *request) {
  request->send(200, "text/html", PAGE_Root);
  //delay(100); //why is this here? TODO: try without.
  debugbuf+="/";
}
//Change the setInterval number above for faster or slower updates from serial to web

/*
void sendRootPage() {        
    debugbuf+="root");
    if (request->args() > 0 )  // Are there any POST/GET Fields ? 
    {
       for ( uint8_t i = 0; i < request->args(); i++ ) {  // Iterate through the fields
            
        }
    }
    server.send ( 200, "text/html", PAGE_Root ); 
}

*/

#define favicon_ico_gz_len 806
const uint8_t favicon_ico_gz[] PROGMEM = {
  
    0x1F, 0x8B, 0x08, 0x08, 0x1A, 0x6D, 0xF7, 0x59,
    0x02, 0x0B, 0x6D, 0x61, 0x73, 0x73, 0x6D, 0x69,
    0x6E, 0x64, 0x31, 0x36, 0x78, 0x31, 0x36, 0x2E,
    0x69, 0x63, 0x6F, 0x00, 0xA5, 0x93, 0x6B, 0x48,
    0x53, 0x61, 0x18, 0xC7, 0x8F, 0x69, 0x1F, 0xBA,
    0x40, 0x26, 0xA5, 0x96, 0x51, 0x76, 0x21, 0xFA,
    0x14, 0x59, 0x29, 0x94, 0x54, 0x66, 0x9A, 0x91,
    0x76, 0x23, 0x8A, 0xC2, 0x22, 0xC2, 0xA2, 0x22,
    0x2A, 0x12, 0x0B, 0xD3, 0x2C, 0xB5, 0x0F, 0x09,
    0x59, 0x59, 0x29, 0x3A, 0xC5, 0xCB, 0xA6, 0xB3,
    0x0C, 0x42, 0x0A, 0xB3, 0x1C, 0x8A, 0xAD, 0xBC,
    0xCE, 0xA9, 0x73, 0x3A, 0xDD, 0xA6, 0x67, 0xEE,
    0x72, 0xE6, 0xE6, 0xBC, 0x4F, 0x49, 0x66, 0xBA,
    0x7F, 0xEF, 0x5E, 0x45, 0x5C, 0x7E, 0xEC, 0x39,
    0x3C, 0xE7, 0xC0, 0xCB, 0xFB, 0x7B, 0x9E, 0xFF,
    0xFF, 0x79, 0xDF, 0xC3, 0x30, 0x2E, 0xE4, 0x71,
    0x77, 0x67, 0xC8, 0xDB, 0x97, 0xB9, 0xE9, 0xC6,
    0x30, 0x9E, 0x0C, 0xC3, 0xEC, 0x20, 0x49, 0x96,
    0xC8, 0xCA, 0xEC, 0x3A, 0x0D, 0x37, 0x66, 0x51,
    0xD8, 0x67, 0x66, 0xE0, 0x48, 0x1A, 0x76, 0xC0,
    0x36, 0x61, 0x85, 0x5C, 0x98, 0x86, 0xEC, 0xBD,
    0xAE, 0xC8, 0xDE, 0xE3, 0x42, 0x33, 0x27, 0xC0,
    0x0D, 0x85, 0xC7, 0x7C, 0x90, 0x77, 0x60, 0x15,
    0xEA, 0x5E, 0x46, 0xCF, 0x6E, 0x9D, 0xE3, 0x68,
    0x4E, 0x4F, 0xA3, 0xBF, 0xBD, 0x11, 0xF5, 0xAF,
    0x63, 0xF0, 0xE5, 0x7A, 0x10, 0x04, 0x21, 0x5E,
    0xF3, 0xEC, 0x2C, 0xBF, 0x14, 0x85, 0x61, 0xEB,
    0xC1, 0x3F, 0xE2, 0x09, 0x49, 0xC6, 0x63, 0x27,
    0x1E, 0x76, 0x3B, 0x26, 0x47, 0x06, 0x50, 0x7A,
    0x39, 0x00, 0x59, 0x3B, 0x19, 0xF0, 0x76, 0x31,
    0xC8, 0xDE, 0xCD, 0x38, 0xF1, 0x8E, 0xCC, 0xDD,
    0xBF, 0x1C, 0xF9, 0x87, 0xDC, 0x21, 0xC9, 0x7C,
    0xE2, 0xCC, 0x93, 0x30, 0xB7, 0xD5, 0x81, 0x1F,
    0xBC, 0x66, 0x11, 0x97, 0x43, 0x3C, 0xE4, 0xF8,
    0xBB, 0xD2, 0xFE, 0xF9, 0x41, 0xAB, 0x91, 0x1B,
    0xB8, 0x12, 0x55, 0xF1, 0x91, 0x98, 0x9E, 0xB2,
    0x39, 0xF1, 0x32, 0xC1, 0x0B, 0xF0, 0xFC, 0xFE,
    0x61, 0xFD, 0x89, 0xE7, 0x30, 0x1F, 0xAA, 0x5B,
    0x70, 0x74, 0x1D, 0x84, 0x11, 0xBE, 0x10, 0x9E,
    0xDC, 0x8A, 0xF2, 0x7B, 0x11, 0x98, 0x1C, 0x1D,
    0xA2, 0xB3, 0x72, 0xF0, 0xBF, 0x87, 0x2D, 0x74,
    0x26, 0x4E, 0x3C, 0xD1, 0xE1, 0xD0, 0x5B, 0x14,
    0xBE, 0x89, 0x70, 0x9B, 0x69, 0x8D, 0xE2, 0xD3,
    0xDB, 0x89, 0xFF, 0xB5, 0x64, 0x8E, 0x1B, 0x20,
    0x2B, 0x4C, 0x9D, 0xD3, 0x60, 0x47, 0xD9, 0xAD,
    0x50, 0xE4, 0x05, 0xAE, 0x58, 0xD0, 0x7B, 0x09,
    0x65, 0x0B, 0x88, 0x9F, 0xA2, 0xE3, 0x1B, 0x51,
    0x7C, 0x6A, 0xDB, 0x3C, 0x97, 0x4B, 0xF6, 0xF1,
    0x43, 0xBC, 0x21, 0x0C, 0xF7, 0x05, 0x2B, 0x2A,
    0xA1, 0xDA, 0x7F, 0x24, 0x5E, 0x75, 0xF2, 0x9B,
    0xBB, 0x6F, 0x19, 0x84, 0x27, 0xB6, 0xD0, 0xFD,
    0x05, 0x87, 0x3D, 0x68, 0x0D, 0xC7, 0xDC, 0xF3,
    0x83, 0x3C, 0x50, 0x9B, 0x91, 0x00, 0xA3, 0xA2,
    0x05, 0x3F, 0xD3, 0x62, 0xF1, 0xF9, 0xDA, 0x41,
    0x0C, 0x2A, 0x5B, 0x31, 0x6E, 0xD6, 0xA3, 0xEC,
    0x46, 0x30, 0xED, 0x2B, 0x08, 0xF5, 0x22, 0xF5,
    0x3D, 0xA9, 0xDF, 0x8F, 0x17, 0xFC, 0x20, 0xE1,
    0xA7, 0xA2, 0x2E, 0x33, 0x09, 0xD2, 0xA2, 0x37,
    0x68, 0x2E, 0xC9, 0x82, 0xA6, 0x4D, 0x82, 0x71,
    0xEB, 0x18, 0x06, 0x4D, 0x46, 0xB4, 0xBC, 0x4F,
    0x47, 0xE3, 0xBB, 0x47, 0x54, 0x83, 0xA1, 0x41,
    0x44, 0x58, 0x6F, 0xDA, 0x87, 0x1F, 0x4A, 0x66,
    0x45, 0x34, 0x57, 0x24, 0x5C, 0x81, 0x41, 0xD5,
    0x8E, 0x9E, 0xE6, 0x5A, 0xB0, 0xB2, 0x46, 0xE8,
    0x94, 0xED, 0x60, 0xE5, 0x52, 0xE8, 0xD5, 0x0A,
    0x8C, 0x8D, 0x8E, 0x40, 0xDF, 0x29, 0x43, 0x65,
    0x62, 0x14, 0xE5, 0xAD, 0xC6, 0x5E, 0x94, 0x47,
    0x9F, 0x81, 0xEC, 0x43, 0x06, 0xEA, 0x78, 0xCF,
    0xA0, 0xAA, 0x11, 0x41, 0x2E, 0xFA, 0x04, 0x13,
    0xAB, 0x04, 0xD7, 0xDD, 0x09, 0x9D, 0xA2, 0x15,
    0xDA, 0xCE, 0x36, 0xE8, 0x55, 0x1D, 0xD0, 0x75,
    0xC9, 0xA1, 0x25, 0xA9, 0x96, 0xD6, 0xA2, 0x3A,
    0xE5, 0x2E, 0xE5, 0x87, 0x59, 0x05, 0xF5, 0x66,
    0xB3, 0x4D, 0xC1, 0x62, 0x34, 0x60, 0x80, 0xE8,
    0xD3, 0x2A, 0x15, 0xE0, 0x7A, 0x7B, 0xC0, 0x69,
    0xD4, 0xE0, 0x58, 0x35, 0xF4, 0x24, 0x69, 0xAD,
    0x8E, 0x16, 0xA8, 0x1A, 0xC5, 0xE8, 0x96, 0x88,
    0x51, 0x1E, 0x73, 0x96, 0xDE, 0xBF, 0x89, 0x7E,
    0x23, 0xAA, 0x9F, 0xDF, 0xC6, 0x60, 0x1F, 0x07,
    0xB3, 0x96, 0x05, 0xD7, 0xD3, 0x85, 0x7E, 0x53,
    0x1F, 0x0C, 0xBD, 0x2C, 0x46, 0x06, 0x2D, 0x30,
    0xEB, 0x34, 0xF4, 0x6B, 0x31, 0xF4, 0xC2, 0x48,
    0x34, 0xF5, 0x93, 0x1E, 0x5D, 0x95, 0xA5, 0x68,
    0x48, 0x8F, 0x9F, 0xBB, 0xFF, 0x7F, 0x20, 0xCD,
    0x4E, 0x46, 0x93, 0xF0, 0x2D, 0xCC, 0x06, 0x1D,
    0xCC, 0x9C, 0x1E, 0x3A, 0xA2, 0x95, 0x95, 0x37,
    0x13, 0xDD, 0x72, 0xF4, 0xB4, 0xD4, 0x13, 0x4E,
    0x05, 0x75, 0x53, 0x0D, 0x4C, 0x3A, 0x16, 0xDD,
    0xD2, 0x1A, 0x88, 0x53, 0xEE, 0x10, 0xDD, 0x9D,
    0xF3, 0xFF, 0x80, 0x95, 0xD3, 0xE0, 0x57, 0xEA,
    0x7D, 0x5A, 0x57, 0x43, 0xE6, 0x64, 0xE9, 0x33,
    0xD2, 0x9E, 0x43, 0xE6, 0x3E, 0xE2, 0x49, 0x8F,
    0x61, 0x13, 0x07, 0x96, 0xD4, 0xD1, 0x36, 0xD7,
    0x40, 0xF4, 0x34, 0x6A, 0xFE, 0xFC, 0x17, 0xDE,
    0x63, 0xC7, 0x59, 0x36, 0xF1, 0x92, 0xF0, 0xED,
    0xE1, 0x79, 0xD4, 0x66, 0x25, 0x43, 0xFC, 0xEA,
    0x01, 0xBE, 0xC6, 0x9C, 0x43, 0x45, 0xDC, 0x25,
    0x7C, 0x8F, 0xBD, 0x08, 0x51, 0x5C, 0x24, 0x24,
    0x59, 0x49, 0x30, 0x4A, 0xAA, 0x30, 0x43, 0x34,
    0x3B, 0x38, 0xE6, 0x3F, 0xE3, 0x2F, 0x0F, 0xF7,
    0xA5, 0x72, 0x7E, 0x04, 0x00, 0x00 
};

void send_favicon_ico(AsyncWebServerRequest *request) {  
  AsyncWebServerResponse *response = request->beginResponse_P(200, "image/x-icon", favicon_ico_gz, favicon_ico_gz_len);
  response->addHeader("Content-Encoding", "gzip");
  request->send(response);
  debugbuf+="favicon.ico\n";
  }

