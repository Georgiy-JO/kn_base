# Some notes about Telegram bot

## Creating of the bot
1. Write to **BotFather bot** in *Telegram* 
    * Choose name for your bot.
    * Choose user_name for you bot.
2.  Get bot HTTP API **TOCKEN** - this is a key to the bot

## Simple work with bot

#### Get status
 See URL:
```
https://api.telegram.org/bot>>BOT_TOKEN<</getme
```

#### Get messages
See URL:
```
https://api.telegram.org/bot>>BOT_TOKEN<</getupdates
```
* from this output you can get the _ID_ of each dialogue with be bot

#### Send messages from the bot's name 
Send to URL:
```
https://api.telegram.org/bot>>BOT_TOKEN<</sendMessage
```
Example: 
```bash
curl -X POST -s -o /dev/null -d chat_id=$VAR_BOT_ID -d text="$VAR_result" https://api.telegram.org/bot$VAR_BOT_TOCKEN/sendMessage
```


## Links
* [Example of using bot for CICD of a project](https://github.com/Georgiy-JO/the_matrices_C_pet) 
