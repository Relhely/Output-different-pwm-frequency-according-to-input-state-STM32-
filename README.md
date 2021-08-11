# Output-different-pwm-frequency-according-to-input-state-STM32
  此專案真的是一個很小的專案，使用的開發版是ALIENTEK Mini STM32
  
  功能是依照數位的接腳輸入來決定輸出的PWM頻率(duty固定50%)
  
  使用接腳可以參照以下圖片
  
# 流程
  由於需要實現的功能屬於較簡單且沒有多線程的任務，所以直接用輪巡的方式不斷讀取輸入接腳，來去決定輸出頻率  
  後續如果此專案需要更精確的準確度，將會改用TI的板子來完成，並且會使每次更改頻率在中斷內執行
  
# 接腳圖
  ![1](https://github.com/Relhely/Output-different-pwm-frequency-according-to-input-state-STM32-/blob/main/Picture/123.png)
