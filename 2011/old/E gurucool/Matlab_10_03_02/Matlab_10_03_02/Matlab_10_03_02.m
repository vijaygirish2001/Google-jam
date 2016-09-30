    

%**************************************************************************
%                                Description
%
%                This Program controls the labjack U3-LV.    
%
%**************************************************************************



%**************************************************************************
% Clear the output window so we can preceed
clc
%**************************************************************************

%**************************************************************************
% Initiate Communication with labjack and get appropriate Drivers for 
% operation
%**************************************************************************
                    %*****************************%  
                    % Configure LabJack by MATLAB %
                    %*****************************%
                    
% Clears Matlab global variables
clear global 

% Loads LabJack UD Function Library
ljud_LoadDriver; 

% Loads LabJack UD constant files
ljud_Constants; 
[Error ljHandle] = ljud_OpenLabJack(LJ_dtU3,LJ_ctUSB,'1',1);

% Check for and display any errors 
Error_Message(Error) 

%reset I/O channels
Error = ljud_ePut(ljHandle, LJ_ioPIN_CONFIGURATION_RESET,0,0,0);
               
               %-----------------------------------------------% 
               %Set FIO7 to be Analog input for momentary contact switch (measure a voltage)%
               %-----------------------------------------------%

               
%Enable FIO7 to be an analog input
Error = ljud_ePut(ljHandle, LJ_ioPUT_ANALOG_ENABLE_BIT,7,1,0);

%Read the voltage at FIO7
[Error volt]= ljud_eGet(ljHandle, LJ_ioGET_AIN,7,0,0);
Error_Message(Error)

%Enable FIO3 to be an analog input for photocell
Error = ljud_ePut(ljHandle, LJ_ioPUT_ANALOG_ENABLE_BIT,3,1,0);

%Read the voltage at FIO3
[Error volt]= ljud_eGet(ljHandle, LJ_ioGET_AIN,3,0,0);
Error_Message(Error)

%keeps measuring the voltage until true = 1                        
true = 1;

%start counting the switch event
global count;
count=0;


%x is a variable to keep a count for the forward sequence
x=0;

%y is a variable to keep a count for the reverse sequence
y=2;



prompt='Please choose an operation:'
userInput=menu(prompt,'Light Sequence','Binary Counter');
choice=userInput;

    [Error volt]= ljud_eGet(ljHandle, LJ_ioGET_AIN,3,1,0);%Measure the voltage at FIO3

if volt>1
if choice==1
lightTimer = UserPrompt();

%Run a binary count using the LED's
else(choice==2)
 myBinaryCounter()

end
end

%**************************************************************************
 
%**************************************************************************
%This is where the magic begin This loop will be continous until the
%photocell is exposed to room light

%*************************************************************************

while(volt > 1)%go inside the "while" statement if the measured voltage is more than 2V (i.e. The switch is ON)
    pause(1)%Wait 1sec to avoid bouncing
%count was preset above as 0 so lights will always start in forward sequence   
    if(mod(count,2) == 0)
%**************************************************************************
%                           Forward Sequence Code
%**************************************************************************

         % Lights will go from left to right
         for(light=0:0) 
            
            %sound for lights
            mySoundOn();
            
            %Check to see if the button is press if it has switch sequences          
            count = ButtonPressChecker();
            
            %Turn the light on
            Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, x, 1, 0);
            
            %Pause for as long as user specified before turning light
            pause(lightTimer) 
            
            %sound for lights off
            mySoundOff();
            
            %Turn the light off
            Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, x, 0, 0);
          
           %Check to see if the button is press if it has switch sequences          
            count = ButtonPressChecker();
           
            %This will increment X so we switch FIO# to control next light
            x=x+1;
            
    %-------------------------------%
    %Built-in reset after every loop%
    %-------------------------------%
            if(x>2) 
                
                %Since their is only 3 lights we must reset our loop value
                x=0;
            end
    %-------------------------------%       
            pause(1)
           % count=ButtonCheck(count);
    disp(count)
        end 
     
     elseif(mod(count,2)~=0) % Reverse the Lights directions
         
%--------------------------------------------------------------------------

%**************************************************************************
%                         Reverse Sequence Code
%**************************************************************************
%NOTE: Refer to comments above to understand code           

            for(light=0:2)
                       
            %sound for lights
            mySoundOn();
            
            %Check to see if the button is press if it has switch sequences          
            count = ButtonPressChecker();
            
                Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, y, 1, 0);
                
                pause(lightTimer)
                
            %sound for lights off
            mySoundOff();
            
            %Check to see if the button is press if it has switch sequences          
            count = ButtonPressChecker();
            
                Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, y, 0, 0);
                
                               
                count = ButtonPressChecker();

                %Reverse count 
                y=y-1;
    %-------------------------------%
    %Built-in reset after every loop%
    %-------------------------------%          
                if(y<0)             %
                                    %
                    y=2;            %
                                    %
                end                 %
    %-------------------------------%        
                        pause(1)   
                        
            end
%--------------------------------------------------------------------------            

%**************************************************************************
%                                RESET
%**************************************************************************
   
%If button is pressed more than twice we must reset the all values
    
        else
        
        %Reset Initial Values
         % count=0;
        %  x=0;
         % y=2;
                
    end
%--------------------------------------------------------------------------
                         %%REPEAT%%
end

%todo list
