function [number]=UserPrompt()
%A GUI promp for the user to input time for the light to stay on.

 prompt={'How long should light display in sec:'};
    dlg_title='Light Timer';
    num_lines=1;
    def={'1'};
    answer = inputdlg(prompt,dlg_title,num_lines,def);
    minlight=answer{1};
    
    minlight=str2double(minlight);
   
    
    number=minlight;
    
    
%Troy Jamison
%Nick R.
%Ece102  Project 1