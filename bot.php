<?php
 require("pub.php");
 require("line.php");

// Get POST body content
$content = file_get_contents('php://input');
// Parse JSON
$events = json_decode($content, true);
$groupId;
// Validate parsed JSON data
if(!is_null($events)){
	global $groupId;
	$replyToken = $events['events']['replyToken'];
	$userID = $events['events']['source']['userId'];
	$sourceType = $events['events']['source']['type'];
	$groupId = $events['events']['source']['groupId'];
	//send_LINE($events['ESP'],$groupId);
	echo "OK2";     
}

if (!is_null($events['ESP'])) {

	global $groupId;
	$access_token = 'be0TDkkZ2drjjPacz274jNhbuO1hb3bVOVNgzPZkfis4FQFW9r5ydZj0FFN5fwLb0S6pLaXwL/s/i62DoabJomYXsAl2kxa+wH3a+N2t83PnjuQKR2BiJtGZRcta74hPF6/+d/o0TUIrskxyq9PgiwdB04t89/1O/w1cDnyilFU=';
	$msg = $events['ESP'];
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
	
	//send_LINE($events['ESP'],$groupId);
		
	echo $groupId;
	}

if (!is_null($events['events'])) {
	echo "line bot";
	// Loop through each event
	foreach ($events['events'] as $event) {
		// Reply only when message sent is in 'text' format
		if ($event['type'] == 'message' && $event['message']['type'] == 'text') {
			// Get text sent
			$text = $event['message']['text'];
			// Get replyToken
			//$replyToken = $event['replyToken'];
			// Get userId
			$userId = $event['source']['userId'];
			// Build message to reply back
			$groupId = $event['source']['groupId'];

			$Topic = "NodeMCU1" ;
			getMqttfromlineMsg($Topic,$text);
			   
			
		}

	}
}

echo "OK3";
?>
