 <?php
  
function send_LINE($msg,$groupId){
 $access_token = 'LWJCoT6Vuz2x0pDhLtyW+wXxpJ+9M7Tx6P5K1bFroeStnMNnh2C46Tnd8H+wWDBg0S6pLaXwL/s/i62DoabJomYXsAl2kxa+wH3a+N2t83O76hO76yDdmyLyFTpQFRW6SIWuCbkkRFwZVhH3wxedPwdB04t89/1O/w1cDnyilFU='; 

  $messages = [
        'type' => 'text',
        'text' => $msg
        //'text' => $text
      ];

      // Make a POST Request to Messaging API to reply to sender
      $url = 'https://api.line.me/v2/bot/message/push';
      $data = [

        'to' => $groupId,
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
