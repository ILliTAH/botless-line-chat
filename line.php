 <?php
  

function send_LINE($msg){
 $access_token = 'xwn+HT7h/C6E9kcHQSeZ8YN4rY3EHdJdNIOtCUDOtWChZUTz6GfNlQoAEVSukGBd0S6pLaXwL/s/i62DoabJomYXsAl2kxa+wH3a+N2t83OvQW5AMKPNphegYkTjy72A2ScvK5xCNqBXej85i0HYmwdB04t89/1O/w1cDnyilFU='; 

  $messages = [
        'type' => 'text',
        'text' => $msg
        'text' => $text
      ];

      // Make a POST Request to Messaging API to reply to sender
      $url = 'https://api.line.me/v2/bot/message/push';
      $data = [

        'to' => 'Uae5e3a6733b33ca1bdace3b0e551556d',
        'messages' => [$messages],
      ];
      $post = json_encode($data);
      $headers = array('Content-Type: application/json', 'Authorization: Bearer ' . $access_token);

      $ch = curl_init($url);
      curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "POST");
      curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
      curl_setopt($ch, CURLOPT_POSTFIELDS, $post);
      curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
      curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 1);
      $result = curl_exec($ch);
      curl_close($ch);

      echo $result . "\r\n"; 
}

?>
