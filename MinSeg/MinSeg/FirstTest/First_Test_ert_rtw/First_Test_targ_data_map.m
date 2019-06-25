  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (kj344bpitr)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% kj344bpitr.M1V4MiddleMotorDriverPWM5D4FST_
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% kj344bpitr.M1V4LeftMotorDriverPWM9D11FST_V
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% kj344bpitr.MagHallorOpticalA1_SampleTime
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% kj344bpitr.PotentimeterA0_SampleTime
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% kj344bpitr.Constant_Value
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% kj344bpitr.frequencyradsec_Gain
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
	  ;% kj344bpitr.amplitude_Gain
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 4;
	
	  ;% kj344bpitr.Constant_Value_gu3mtjteyd
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 5;
	
	  ;% kj344bpitr.Constant_Value_brgwhq3kc4
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% kj344bpitr.SaturationVsupplytoVsupply_Lowe
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% kj344bpitr.conversiontodutycycleconverttou
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% kj344bpitr.SaturationVsupplytoV_jnkxaijlln
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 2;
	
	  ;% kj344bpitr.conversiontodutycycl_doeewvgkt5
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ehtkn3l1lnu)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% ehtkn3l1lnu.nssj4jzuto
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ehtkn3l1lnu.k1wbzrfoac
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ehtkn3l1lnu.brdzsqwxul
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ehtkn3l1lnu.oe2llo41zb
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% ehtkn3l1lnu.gbdebvefj0
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ehtkn3l1lnu.l04xubfrqx
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% ehtkn3l1lnu.igmtn4uwqe
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ehtkn3l1lnu.lqtlph4q1s
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ehtkn3l1lnu.jkzqj250i2
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ehtkn3l1lnu.av5hbpqixx
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ehtkn3l1lnu.dxf3xrvwg2
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ehtkn3l1lnu.oxyjwxp0vx
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ehtkn3l1lnu.mtmixjck4d
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 10;
    sectIdxOffset = 4;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ae1hsh54atj)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% ae1hsh54atj.o0ew4b333g
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ae1hsh54atj.nmrad4dj5p
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% ae1hsh54atj.nm4ogbjzzh
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ae1hsh54atj.hzojowljmh
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ae1hsh54atj.oczue13h2w
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ae1hsh54atj.pmtrqccr3m
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% ae1hsh54atj.o0tbkwuyf1
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ae1hsh54atj.ifag4sswus
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ae1hsh54atj.jmkuyg4iee
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ae1hsh54atj.ap022s3t1h
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ae1hsh54atj.ix2a0qfuxq
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ae1hsh54atj.axjrgt3lsk
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% ae1hsh54atj.o0dbdqnc55.LoggedData
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ae1hsh54atj.e1f5py235s.LoggedData
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 6;
	
	  ;% ae1hsh54atj.chyjzykbic.LoggedData
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 7;
	
	  ;% ae1hsh54atj.o3wn0tb1b3.LoggedData
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 8;
	
	  ;% ae1hsh54atj.ksuutjgvu0.LoggedData
	  section.data(5).logicalSrcIdx = 16;
	  section.data(5).dtTransOffset = 9;
	
	  ;% ae1hsh54atj.nlti3v0r5w.LoggedData
	  section.data(6).logicalSrcIdx = 17;
	  section.data(6).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% ae1hsh54atj.gj54savxhx
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ae1hsh54atj.aytwp2unti
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ae1hsh54atj.gbk04ppr3j
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ae1hsh54atj.dqorz0yahz
	  section.data(4).logicalSrcIdx = 21;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ae1hsh54atj.olfqgtom50
	  section.data(5).logicalSrcIdx = 22;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ae1hsh54atj.hdsjki5uno
	  section.data(6).logicalSrcIdx = 23;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ae1hsh54atj.k0wijwfcyt
	  section.data(7).logicalSrcIdx = 24;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ae1hsh54atj.ffemrwgf2d
	  section.data(8).logicalSrcIdx = 25;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ae1hsh54atj.oo0trjtat3
	  section.data(9).logicalSrcIdx = 26;
	  section.data(9).dtTransOffset = 8;
	
	  ;% ae1hsh54atj.f4amkqjpbt
	  section.data(10).logicalSrcIdx = 27;
	  section.data(10).dtTransOffset = 9;
	
	  ;% ae1hsh54atj.kdfebdzljj
	  section.data(11).logicalSrcIdx = 28;
	  section.data(11).dtTransOffset = 10;
	
	  ;% ae1hsh54atj.lfn2bsd0z4
	  section.data(12).logicalSrcIdx = 29;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2819537650;
  targMap.checksum1 = 2038018802;
  targMap.checksum2 = 2089416294;
  targMap.checksum3 = 2437840353;

