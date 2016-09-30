function [count]=ButtonPressChecker()
%


%Configure LabJack by MATLAB
%clear global % Clears Matlab global variables
 
ljud_LoadDriver; % Loads LabJack UD Function Library
ljud_Constants; % Loads LabJack UD constant files
[Error ljHandle] = ljud_OpenLabJack(LJ_dtU3,LJ_ctUSB,'1',1);
Error_Message(Error) % Check for and display any errors 

%reset I/O channels
%Error = ljud_ePut(ljHandle, LJ_ioPIN_CONFIGURATION_RESET,0,0,0);

%Set FIO7 to be Analog input (measure a voltage)
Error = ljud_ePut(ljHandle, LJ_ioPUT_ANALOG_ENABLE_BIT,7,1,0);%Enable FIO4 to be an analog input
[Error volt]= ljud_eGet(ljHandle, LJ_ioGET_AIN,7,0,0);%Read the voltage at FIO4 

Error_Message(Error)
true = 1;%keeps measuring the voltage until true = 1
global count;%start counting the switch event
disp('where are at the button check')
%while true==1 
    
    [Error volt]= ljud_eGet(ljHandle, LJ_ioGET_AIN,7,1,0);%Measure the voltage at FIO7
    
    if(volt > 1)%go inside the "if" statement if the measured voltage is more than 2V (i.e. The switch is ON)
        pause(1)%Wait 1sec to avoid bouncing
        
        %From here, we can tell LabJack to take an action 
        disp('switch is on')%Tell the user that the switch was pressed.
         count = count + 1%increment by 1 every time switch is pressed.
            pause(1)
          fprintf('count =  %d times\n', count);%Show how many times the switch is pressed so far!
    
        %if(count==2)
         %  disp(count)
          %  disp('got to makesure')
           % count=0;
            %disp(count)
        end
    %else
        %count=count;
        %disp('im here now')
   
  %  break
    %end
    %break
%end

