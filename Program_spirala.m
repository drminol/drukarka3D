clear z12 z22 z32 z1 z2 z3
if ~exist('drukarka')
    druk=serial('/dev/ttyUSB2')
    druk.BaudRate=57600;
    
end
try
    fopen(druk)
catch blad
    
end

fprintf(druk, 'x20000 y20000 z20000'); %reset polozenia
pause(3);

col1=line([0 0],[0.5 0.5],[0 6]);
col2=line([0 0],[1.5 1.5],[0 6]);
col3=line([1 1],[1 1],[0 6]);
arm1=line(0,0,0);
arm2=line(0,0,0);
arm3=line(0,0,0);
platform=line(0.5,1,2);

for t=10:0.1:40
    
xc=0.1*sin(t)+0.5;
yc=0.1*cos(t)+1;
zc=0.05*t;
    
x1=0;
y1=0.5;
x2=0;
y2=1.5;
x3=1;
y3=1;
r=1;

if exist('z1')
z12=z1;
z22=z2;
z32=z3;
end


z1=zc+sqrt(r^2-(x1-xc)^2-(y1-yc)^2);
z2=zc+sqrt(r^2-(x2-xc)^2-(y2-yc)^2);
z3=zc+sqrt(r^2-(x3-xc)^2-(y3-yc)^2);



set(arm1,'XData',[x1,xc],'YData',[y1,yc],'ZData',[z1,zc]);
set(arm2,'XData',[x2,xc],'YData',[y2,yc],'ZData',[z2,zc]);
set(arm3,'XData',[x3,xc],'YData',[y3,yc],'ZData',[z3,zc]);

try
   krok1=z12-z1;
   krok2=z22-z2;
   krok3=z32-z3;
   krok11=num2str(round(krok1*10000));
   krok21=num2str(round(krok2*10000));
   krok31=num2str(round(krok3*10000));
   komunikat=['x' krok11 ' y' krok21 ' z' krok31 '\n']
   fprintf(druk, komunikat)
   
   % Komunikacja obustronna
   while (druk.BytesAvailable==0)
   end
   
   while (druk.BytesAvailable>0)
       fscanf(druk);
   end
   
 
   
catch err
    
end

view(-27,-10);
hold on
plot3(xc,yc,zc,'o')

end




