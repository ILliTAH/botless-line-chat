<?php
$access_token = 'xwn+HT7h/C6E9kcHQSeZ8YN4rY3EHdJdNIOtCUDOtWChZUTz6GfNlQoAEVSukGBd0S6pLaXwL/s/i62DoabJomYXsAl2kxa+wH3a+N2t83OvQW5AMKPNphegYkTjy72A2ScvK5xCNqBXej85i0HYmwdB04t89/1O/w1cDnyilFU=';

$url = 'https://api.line.me/v1/oauth/verify';

$headers = array('Authorization: Bearer ' . $access_token);

$ch = curl_init($url);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 1);
$result = curl_exec($ch);
curl_close($ch);

echo $result;
?>