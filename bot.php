<?php
require("pub.php");
require("line.php");

// Get POST body content
$content = file_get_contents('php://input');
// Parse JSON
$events = json_decode($content, true);

if (!is_null($events['events'])) {
	echo "line bot";
	// Loop through each event
	foreach ($events['events'] as $event) {
		// Reply only when message sent is in 'text' format
		if ($event['type'] == 'message' && $event['message']['type'] == 'text') {
			// Get text sent
			global $groupId ='';
			$text = $event['message']['text'];
			// Get replyToken
			//$replyToken = $event['replyToken'];
			// Get userId
			$userId = $event['source']['userId'];
			// Build message to reply back
		 	$groupId = $event['source']['groupId'];

			$Topic = "NodeMCU1" ;
			getMqttfromlineMsg($Topic,$text);

			   //C18dd6337a111c9b2e6b5aef91b2569ca

		}
	}
}

if (!is_null($events['ESP'])) {
	
	send_LINE($events['ESP']);
		
	
	}

echo "OK3";
?>
