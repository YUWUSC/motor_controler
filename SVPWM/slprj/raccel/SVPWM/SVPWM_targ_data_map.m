    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
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
        ;% Auto data (rtP)
        ;%
            section.nData     = 51;
            section.data(51)  = dumData; %prealloc

                    ;% rtP._Vdc2f2SVPWM_sldd_
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP._m2f2SVPWM_sldd_
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.RepeatingSequence_rep_seq_y
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.Gain2_Gain
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% rtP.Gain3_Gain
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 6;

                    ;% rtP.StateSpace_AS_param
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 7;

                    ;% rtP.StateSpace_BS_param
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 43;

                    ;% rtP.StateSpace_CS_param
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 85;

                    ;% rtP.StateSpace_DS_param
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 157;

                    ;% rtP.StateSpace_X0_param
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 241;

                    ;% rtP.LookUpTable1_bp01Data
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 247;

                    ;% rtP.SineWave_Bias
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 250;

                    ;% rtP.SineWave_Freq
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 251;

                    ;% rtP.SineWave_Phase
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 252;

                    ;% rtP.Gain3_Gain_byafyznv0k
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 255;

                    ;% rtP.Gain1_Gain
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 264;

                    ;% rtP.Switch_Threshold
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 265;

                    ;% rtP.Gain1_Gain_gnhgdq2zzz
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 266;

                    ;% rtP.Gain_Gain
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 267;

                    ;% rtP.Switch1_Threshold
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 268;

                    ;% rtP.Gain2_Gain_lxbjdzc3ab
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 269;

                    ;% rtP.Switch2_Threshold
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 270;

                    ;% rtP.Gain_Gain_o3ussx2pey
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 271;

                    ;% rtP.Gain1_Gain_a1wggbqhys
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 272;

                    ;% rtP.Gain_Gain_jtfu24yj43
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 273;

                    ;% rtP.u4_Value
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 274;

                    ;% rtP.uRon_Gain
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 275;

                    ;% rtP.Switch_Threshold_jdj5zhvmwv
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 276;

                    ;% rtP.Saturation_UpperSat
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 277;

                    ;% rtP.Saturation_LowerSat
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 278;

                    ;% rtP.UnitDelay_InitialCondition
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 279;

                    ;% rtP.donotdeletethisgain_Gain
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 280;

                    ;% rtP.donotdeletethisgain_Gain_d5clbn1ab5
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 281;

                    ;% rtP.donotdeletethisgain_Gain_dii0kh5zng
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 282;

                    ;% rtP.Kv1_Gain
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 283;

                    ;% rtP.donotdeletethisgain_Gain_f0n5ohe52n
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 284;

                    ;% rtP.donotdeletethisgain_Gain_cljduyemw5
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 285;

                    ;% rtP.donotdeletethisgain_Gain_fprakrrw0l
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 286;

                    ;% rtP.Kv_Gain
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 287;

                    ;% rtP.Constant_Value
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 288;

                    ;% rtP.Constant1_Value
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 289;

                    ;% rtP.Constant2_Value
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 290;

                    ;% rtP.Constant3_Value
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 291;

                    ;% rtP.Constant4_Value
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 292;

                    ;% rtP.Constant5_Value
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 293;

                    ;% rtP.Constant6_Value
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 294;

                    ;% rtP.Constant7_Value
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 295;

                    ;% rtP.Constant8_Value
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 296;

                    ;% rtP.Constant9_Value
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 297;

                    ;% rtP.Constant_Value_ffpsqzlbdy
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 298;

                    ;% rtP.Constant_Value_kboz1tvd2g
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 299;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
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
        nTotSects     = 2;
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
        ;% Auto data (rtB)
        ;%
            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% rtB.a1jevbgg4x
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.jbljr5tq4u
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 12;

                    ;% rtB.eiihwmjf1j
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 18;

                    ;% rtB.exnbmwz04i
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 20;

                    ;% rtB.l35oohpje4
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 26;

                    ;% rtB.dqwh3ca4xi
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 32;

                    ;% rtB.en3wjyqdju
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 35;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtB.iusmv3md3a
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.pjks0m0pmo
                    section.data(2).logicalSrcIdx = 8;
                    section.data(2).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
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
        nTotSects     = 3;
        sectIdxOffset = 2;

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
        ;% Auto data (rtDW)
        ;%
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.jiydzlq20v
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.djelptucdk
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% rtDW.mpy40nreq3.AS
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.ahjsbkznjq.LoggedData
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.kt5gzitgzu.LoggedData
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 3;

                    ;% rtDW.h21b5dj40j.LoggedData
                    section.data(4).logicalSrcIdx = 5;
                    section.data(4).dtTransOffset = 9;

                    ;% rtDW.oihcveypcc.LoggedData
                    section.data(5).logicalSrcIdx = 6;
                    section.data(5).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.h0oh5ydh3u
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
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


    targMap.checksum0 = 2154651661;
    targMap.checksum1 = 2785804129;
    targMap.checksum2 = 50835171;
    targMap.checksum3 = 380630390;

