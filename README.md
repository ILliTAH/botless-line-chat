# LINE-BOT-PHP-NUBER-RANDOM

### How to get groupId 

>เปิดไฟล์ bot.php
```
			$Topic = "NodeMCU1" ;
			getMqttfromlineMsg($Topic,$text);

```

>แก้ไขการส่ง text ไปที่ arduino เป็นการส่งค่า groupId
```
			$Topic = "NodeMCU1" ;
			getMqttfromlineMsg($Topic,$groupId);

```

>Serial monitor จะแสดงค่า groupId xxxxxxxxxxxxxx
```

Incoming message --> /botlesslinechat/gearname/NodeMCU1 : xxxxxxxxxxxxxxxx
...
...
```

>เปิดไฟล์ นำ groupId มาใส่ที่ไฟล์ line.php
```
'to' => 'xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx',
```

- [x] Chat Room
- [X] Chat Group
- [ ] Dynamic Chat