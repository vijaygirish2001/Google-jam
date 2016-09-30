function myBinaryCounter()
%This function is a binary counter that counts in binary while displaying
%the count visually with LED's
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
s
%reset I/O channels
Error = ljud_ePut(ljHandle, LJ_ioPIN_CONFIGURATION_RESET,0,0,0);
               
               %-----------------------------------------------% 
               %Set FIO7 to be Analog input (measure a voltage)%
               %-----------------------------------------------%

               
 %Enable FIO7 to be an analog input
 Error = ljud_ePut(ljHandle, LJ_ioPUT_ANALOG_ENABLE_BIT,7,1,0);
 
 %Read the voltage at FIO7
 [Error volt]= ljud_eGet(ljHandle, LJ_ioGET_AIN,7,0,0);
 Error_Message(Error)

%**************************************************************************
                        %---------------%
                        % Set Variables %
                        %---------------%
                        
                        
                        
%keeps measuring the voltage until true = 1                        
true = 1;



%**************************************************************************
 

%*************************************************************************
while true == 1  
    
%
%**************************************************************************
%                           Binary Code
%**************************************************************************

         % Lights will go from left to right
         for(light=0:7) 
            
          mybincode=dec2bin(light,3);
          
          
%-------------------------------------------------------------------------- 
%                            Binary 0
            
                              number=dec2bin(0,3);
            if (strcmp(mybincode,number))
             
                %No light will ever display   
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 4, 0, 0);
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 5, 0, 0);
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 6, 0, 0);
                                disp(mybincode)
                                 pause(1)
            end
%--------------------------------------------------------------------------
%                            Binary 1
                       number=dec2bin(1,3);
             if strcmp(mybincode,number)
             
                %Turn lights on
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 4, 1, 0);
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 5, 0, 0);
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 6, 0, 0);
                                
                                disp(mybincode)
                                   pause(1)
                                 
                 %Turn lights off                  
            Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 4, 0, 0);
             end
%--------------------------------------------------------------------------                    
%                            Binary 2
            number=dec2bin(2,3);
            if strcmp(mybincode,number)
           
                %Turn lights on
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 4, 0, 0);
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 5, 1, 0);
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 6, 0, 0);
                                
                                disp(mybincode)       
                                    pause(1)
                  
                 %Turn lights off                   
            Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 5, 0, 0);
            end
%--------------------------------------------------------------------------
%                                 Binary 3
                number=dec2bin(3,3);
            if strcmp(mybincode,number)
             
                %Turn lights on
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 4, 1, 0);
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 5, 1, 0);
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 6, 0, 0);
                                
                               disp(mybincode)
                                  pause(1)
             
                  %Turn lights off                
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 4, 0, 0);
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 5, 0, 0);
            end 
             
%--------------------------------------------------------------------------
%                                    Binary 4
            number=dec2bin(4,3);
            if strcmp(mybincode,number)
             
                %Turn lights on
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 4, 0, 0);
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 5, 0, 0);
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 6, 1, 0);
                  
                        disp(mybincode) 
                            pause(1)
               
                 %Turn lights off           
            Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 6, 0, 0);
            end               
%--------------------------------------------------------------------------
%                                   Binary 5
            number=dec2bin(5,3);
            if strcmp(mybincode,number)
             
                %Turn lights on
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 4, 1, 0);
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 5, 0, 0);
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 6, 1, 0);
                                
                            disp(mybincode)
                                pause(1)
                
                 %Turn lights off                
            Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 4, 0, 0);
            Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 6, 0, 0);
            end
%--------------------------------------------------------------------------
%                                  Binary 6
             number=dec2bin(6,3);
            if strcmp(mybincode,number)
             
                %Turn lights on                
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 4, 0, 0);
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 5, 1, 0);
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 6, 1, 0);
                
                        disp(mybincode)
                           pause(1)
                           
                %Turn lights off
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 5, 0, 0);
             Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 6, 0, 0);
            end
%--------------------------------------------------------------------------
%                                 Binary 7
            number=dec2bin(7,3);
            if strcmp(mybincode,number)

                %Turn on lights
            Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 4, 1, 0);
            Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 5, 1, 0);
            Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 6, 1, 0);
            
                        disp(mybincode) %Print binary output
                        pause(1) %Wait 1 sec then proceed
            
                %Turn lights off
            Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 4, 0, 0);
            Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 5, 0, 0);
            Error = ljud_ePut (ljHandle, LJ_ioPUT_DIGITAL_BIT, 6, 0, 0);
               
            end
         end
end
        
       