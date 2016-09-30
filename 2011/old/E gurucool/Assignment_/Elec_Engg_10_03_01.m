clc;
clear all;
close all;
load var.mat;   % Default Temparature -RPM map
disp(['Temperature Fan''s Rotation']);
disp([num2str(temp_rpm(5,1)) 'C  ' num2str(temp_rpm(5,2)) 'rpm']);
a=0;
p='    ';
while(a==0)
p=input('Enter PIN to change system paramaters: ','s');
    if length(p)==4
        if( p==pin)
            break;
        else
            tic;
            disp(['Wrong PIN, reenter PIN']);
            while(toc<3)
            end
        end
    else
        disp(['PIN should be of four characters']);
    end
end


while(a==0)
    clc
    disp(['  ']);
    disp([' Please select one of the following:']);
    disp(['1. Change PIN number']);
    disp(['2. Stop Motor']);
    disp(['3. Start Motor']);
    disp(['4. Change Direction']);
    disp(['5. Configure Temperature as RPM']);
    n=input('Enter option (Enter 0 to exit):');
    ambient=17;
    
    if length(n)>0
    if n>=0 && n<=5
        switch n
        case 0
        return;      
        case 1
            p=input('Enter old PIN number:','s');
            if length(p)==4
                if( p==pin)
                    p=input('Enter new PIN number:','s');
                    if length(p)==4
                        p1=input('Reenter new PIN number:','s');
                        if length(p)==length(p1)
                        elseif p==p1
                            pin=p;
                            save('var.mat','pin','temp_rpm');
                            disp(['New PIN saved']);
                        else
                            disp(['Not matching with previously entered new PIN, retry']);
                        end
                    else
                        disp(['New PIN should be four characters wide']);
                    end
                else
                    disp(['Wrong PIN, retry']);         
                end
            else
            disp(['PIN should be of four characters']);
            end
        case 2
            if motor(length(motor))>0
                if toc>1
                motor=[ motor ones(1,(toc-1)*1000)*temp_rpm(ambient-14,2) temp_rpm(ambient-14,2):-1:0];
                t=[t linspace(t(length),t(length)+1,length([temp_rpm(ambient-14,2):0]))];
                plot(t,motor);
                end
            else
                 motor=[ motor ones(1,(toc-1)*1000)*(-temp_rpm(ambient-14,2)) -temp_rpm(ambient-14,2):0];
                t=[t linspace(t(length),t(length)+1,length([temp_rpm(ambient-14,2):0]))];
                plot(t,motor);
            
            end    
        case 3
            motor=0:temp_rpm(ambient-14,2);
                      
            tic
            t=linspace(0,1,length(motor));
            plot(t,motor);
            grid;
            hold;
        case 4   
            if toc>1
            motor=[ motor ones(1,(toc-1)*1000)*temp_rpm(ambient-14,2) temp_rpm(ambient-14,2):-1:0 0:-1:temp_rpm(ambient-14,2)];
            t=[t linspace(t(length),t(length)+1,length(motor)-length(t))];
            plot(t,motor);
            
            end
        case 5
            disp(['Temperature RPM (Configured values)']);
            temp_rpm    
            tp=input('Enter the temperature in celsius for which you wish to program the rpm(15 to 35):');      %tp is the temperature
            if length(tp)>0
                if tp>=15 && tp<=35
                     rp=input('Enter the speed in rpm:');
                   while(length(rp)<1)
                       rp=input('Enter the speed in rpm:');
                   end
                       temp_rpm(tp-14,2)=rp;
                       save('var.mat','pin','temp_rpm');
                end
            end
            
        case 6
          
            am=input('Enter the ambient temperature in celsius ');      %tp is the temperature
            if length(am)>0
                if am>=15 && am<=35
                     ambient=am;
                end
            end
          

        otherwise
        end  
    else
            
            disp(['Invalid option']);
            
        
    end
    end
 end
