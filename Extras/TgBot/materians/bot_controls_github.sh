#!/bin/bash 
VAR_file="src/VAR.txt"
VAR_comment=$(cat $VAR_file)
VAR_bot_api_token=$BOT_URL_API_TOKEN
VAR_bot_chat_ID=$CHAT_ID
VAR_JOB_STATUS=$JOB_STATUS
VAR_PROJECT=${GITHUB_REPOSITORY##*/}
# https://api.telegram.org/bot$VAR_bot_api_token/getme - bot info
# https://api.telegram.org/bot$VAR_bot_api_token/getupdates  - log
VAR_message_URL="https://api.telegram.org/bot$VAR_bot_api_token/sendMessage"


if [ -z "$VAR_bot_api_token" ] || [ -z "$VAR_bot_chat_ID" ]; then
  echo "Telegram notifications impossible: telegram tocken or ID not set."
  exit 0
fi

echo "Sending message to the bot!"

# VAR_message="$GITHUB_TRIGGERING_ACTOR|$VAR_PROJECT|$GITHUB_JOB->"
VAR_message="$VAR_PROJECT|$GITHUB_JOB->"
if [ "$VAR_JOB_STATUS" = "success" ]; then      #✅ - succeed
    VAR_message="$VAR_message✅"
elif [ "$VAR_JOB_STATUS" = "failure" ]; then    #❎ - failed
    VAR_message="$VAR_message❌"
else                                            #🛑 - canceled
    VAR_message="$VAR_message🛑"
fi

if [ -n "$VAR_comment" ]; then
    VAR_message="$VAR_message| $VAR_comment"
fi

curl -X POST -s -o /dev/null -d chat_id=$VAR_bot_chat_ID -d text="$VAR_message" $VAR_message_URL

exit 0

