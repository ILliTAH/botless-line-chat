<?php
 require("pub.php");
 require("line.php");

// Get POST body content
$content = file_get_contents('php://input');
// Parse JSON
$events = json_decode($content, true);
// Validate parsed JSON data
if(!is_null($events)){
	
	$replyToken = $events['events'][0]['replyToken'];
	$userID = $events['events'][0]['source']['userId'];
	$sourceType = $events['events'][0]['source']['type'];
	$groupId = $events['events'][0]['source']['groupId'];
	send_LINE($events['ESP'],$groupId);
	       
}

if (!is_null($events['ESP'])) {

	send_LINE($events['ESP'],$groupId);
		
	echo "OK";
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

			$Topic = "NodeMCU1" ;
			getMqttfromlineMsg($Topic,$text);
			   
			
		}

	}
}
echo $groupId;
echo $userId;
echo "OK3";
?>
