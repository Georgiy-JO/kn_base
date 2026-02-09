#!/bin/bash 
VAR_file="src/VAR.txt"
VAR_comment=$(cat $VAR_file)
VAR_bot_api_token="<bot_token>"
VAR_bot_chat_ID="<chat_id>"
# https://api.telegram.org/bot$VAR_bot_api_token/getme - bot info
# https://api.telegram.org/bot$VAR_bot_api_token/getupdates  - log
VAR_message_URL="https://api.telegram.org/bot$VAR_bot_api_token/sendMessage"


if [ -z "$VAR_bot_api_token" ] || [ -z "$VAR_bot_chat_ID" ]; then
  echo "Telegram notifications impossible: telegram tocken or ID not set."
  exit 0
fi

echo "Sending message to the bot!"

# VAR_message="$GITLAB_USER_LOGIN|$CI_PROJECT_NAME|$CI_JOB_NAME->"
VAR_message="$CI_PROJECT_NAME|$CI_JOB_NAME->"
if [ "$CI_JOB_STATUS" = "success" ]; then      #✅ - succeed
    VAR_message="$VAR_message✅$VAR_comment"
elif [ "$CI_JOB_STATUS" = "failed" ]; then     #❎ - failed
    VAR_message="$VAR_message❌$VAR_comment"
else                                           #🛑 - canceled
    VAR_message="$VAR_message🛑$VAR_comment"
fi

curl -X POST -s -o /dev/null -d chat_id=$VAR_bot_chat_ID -d text="$VAR_message" $VAR_message_URL

exit 0

