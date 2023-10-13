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
            section.nData     = 74;
            section.data(74)  = dumData; %prealloc

                    ;% rtP.Ib
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.S
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 9;

                    ;% rtP.St
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 10;

                    ;% rtP.Vb0
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 11;

                    ;% rtP.Xe0
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 14;

                    ;% rtP.alpha_L0
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 17;

                    ;% rtP.alpha_switch
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 18;

                    ;% rtP.cbar
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 19;

                    ;% rtP.cd_c1
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 20;

                    ;% rtP.cd_c2
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 21;

                    ;% rtP.cd_m1
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 22;

                    ;% rtP.cd_m2
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 23;

                    ;% rtP.dCYdRud
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 24;

                    ;% rtP.dCYdbeta
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 25;

                    ;% rtP.depsda
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 26;

                    ;% rtP.euler0
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 27;

                    ;% rtP.g
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 30;

                    ;% rtP.lt
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 31;

                    ;% rtP.m
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 32;

                    ;% rtP.n
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 33;

                    ;% rtP.pqr0
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 34;

                    ;% rtP.u0
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 37;

                    ;% rtP.umax
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 42;

                    ;% rtP.umin
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 47;

                    ;% rtP.Polynomial_Coefs
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 52;

                    ;% rtP.Gain_Gain
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 56;

                    ;% rtP.phithetapsi_WrappedStateUpperValue
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 57;

                    ;% rtP.phithetapsi_WrappedStateLowerValue
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 58;

                    ;% rtP.Gain_Gain_bxpznsjmpu
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 59;

                    ;% rtP.Gain_Gain_h1ktjeexx1
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 60;

                    ;% rtP.Gain_Gain_brtoidrzvi
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 61;

                    ;% rtP.Gain_Gain_o2nz4hlc0y
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 62;

                    ;% rtP.Gain_Gain_grtmmf3s4r
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 63;

                    ;% rtP.Gain_Gain_nkk2ewvwrs
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 64;

                    ;% rtP.Gain_Gain_cyh2wwurhc
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 65;

                    ;% rtP.Gain_Gain_hnrzzhh2v0
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 66;

                    ;% rtP.Gain_Gain_acmismgbcw
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 67;

                    ;% rtP.Limitaltitudetotroposhere_UpperSat
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 68;

                    ;% rtP.Limitaltitudetotroposhere_LowerSat
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 69;

                    ;% rtP.LapseRate_Gain
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 70;

                    ;% rtP.uT0_Gain
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 71;

                    ;% rtP.rho0_Gain
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 72;

                    ;% rtP.LimitaltitudetoStratosphere_UpperSat
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 73;

                    ;% rtP.LimitaltitudetoStratosphere_LowerSat
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 74;

                    ;% rtP.gR_Gain
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 75;

                    ;% rtP.Gain_Gain_bxawv450gg
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 76;

                    ;% rtP.Gain1_Gain
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 77;

                    ;% rtP.Step1_Time
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 78;

                    ;% rtP.Step1_Y0
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 79;

                    ;% rtP.Step1_YFinal
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 80;

                    ;% rtP.Gain1_Gain_hfbnedsnqk
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 81;

                    ;% rtP.Gain2_Gain
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 82;

                    ;% rtP.Gain_Gain_bfommv4lak
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 83;

                    ;% rtP.Gain2_Gain_dwlwh44krh
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 84;

                    ;% rtP.Gain_Gain_ftxlqxfaiq
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 85;

                    ;% rtP.Gain_Gain_lov5qcjzgk
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 86;

                    ;% rtP.Gain_Gain_l2z5belp2u
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 87;

                    ;% rtP.Constant_Value
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 88;

                    ;% rtP.Constant1_Value
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 89;

                    ;% rtP.Constant_Value_lag24fa1pj
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 90;

                    ;% rtP.Constant1_Value_mx4lv2w3em
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 91;

                    ;% rtP.ControlEffectivenessMatrix_Value
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 92;

                    ;% rtP.Constant1_Value_ogzj0ybhah
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 101;

                    ;% rtP.Constant_Value_jauwwxrr5h
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 110;

                    ;% rtP.Constant_Value_gstis4eggm
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 113;

                    ;% rtP.Constant1_Value_mrpwt2vxxm
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 114;

                    ;% rtP.Constant2_Value
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 115;

                    ;% rtP.AltitudeofTroposphere_Value
                    section.data(68).logicalSrcIdx = 67;
                    section.data(68).dtTransOffset = 124;

                    ;% rtP.Constant_Value_fqrpfjqhfg
                    section.data(69).logicalSrcIdx = 68;
                    section.data(69).dtTransOffset = 125;

                    ;% rtP.SeaLevelTemperature_Value
                    section.data(70).logicalSrcIdx = 69;
                    section.data(70).dtTransOffset = 126;

                    ;% rtP.Constant3_Value
                    section.data(71).logicalSrcIdx = 70;
                    section.data(71).dtTransOffset = 127;

                    ;% rtP.Constant1_Value_oqyl4nphju
                    section.data(72).logicalSrcIdx = 71;
                    section.data(72).dtTransOffset = 128;

                    ;% rtP.mew1_Value
                    section.data(73).logicalSrcIdx = 72;
                    section.data(73).dtTransOffset = 129;

                    ;% rtP.mew2_Value
                    section.data(74).logicalSrcIdx = 73;
                    section.data(74).dtTransOffset = 132;

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
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 113;
            section.data(113)  = dumData; %prealloc

                    ;% rtB.c10sww4qfc
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.etd4am2wmj
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% rtB.iz1lzcyd3a
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 6;

                    ;% rtB.d1t3jcdw1w
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 9;

                    ;% rtB.pwlerz4zmu
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 10;

                    ;% rtB.kwagzwu5gd
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 13;

                    ;% rtB.iam1jhjhep
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 14;

                    ;% rtB.pntd0wqwje
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 17;

                    ;% rtB.njx2l41pcu
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 18;

                    ;% rtB.ftrrsvm4qz
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 19;

                    ;% rtB.o01hcd1hwc
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 20;

                    ;% rtB.fgkyl4gpeb
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 21;

                    ;% rtB.gw5me3glut
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 22;

                    ;% rtB.mf4semtcii
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 23;

                    ;% rtB.f2sno0tuqf
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 24;

                    ;% rtB.dpzkdmkvzx
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 25;

                    ;% rtB.ozpmvwdhed
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 26;

                    ;% rtB.gu4fdkfnej
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 27;

                    ;% rtB.ccfglqcque
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 28;

                    ;% rtB.fzzfxafjlu
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 29;

                    ;% rtB.akshdvntgj
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 32;

                    ;% rtB.hmcdusmxx2
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 41;

                    ;% rtB.abopebv22d
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 44;

                    ;% rtB.pt5pzvbxss
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 53;

                    ;% rtB.oyvt50li2v
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 54;

                    ;% rtB.cnwqcjfxbd
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 55;

                    ;% rtB.lfcw5ky34x
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 56;

                    ;% rtB.ppzmvjgz3o
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 57;

                    ;% rtB.ilkefjjycy
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 58;

                    ;% rtB.g5412zpwqu
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 59;

                    ;% rtB.fdgklgayoh
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 60;

                    ;% rtB.idxg52v4a5
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 61;

                    ;% rtB.mkj2w3ap12
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 62;

                    ;% rtB.ixd3mmmbvw
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 63;

                    ;% rtB.jvposjqlvw
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 64;

                    ;% rtB.nlfhqpdwsg
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 65;

                    ;% rtB.lzdkj2knvd
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 66;

                    ;% rtB.jjoh1jbcal
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 67;

                    ;% rtB.bzatbelz3c
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 68;

                    ;% rtB.iirpepr453
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 69;

                    ;% rtB.cz4qtuhpp2
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 70;

                    ;% rtB.lgam5r5wm4
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 71;

                    ;% rtB.l2a1ipflwy
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 72;

                    ;% rtB.kyodpk4kvr
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 73;

                    ;% rtB.galszwoxqw
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 74;

                    ;% rtB.hmndehnp3x
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 75;

                    ;% rtB.fph3doyxdf
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 76;

                    ;% rtB.nqkem2zrkc
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 77;

                    ;% rtB.m2bzifekpx
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 78;

                    ;% rtB.dwusv2m5gc
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 79;

                    ;% rtB.lgmerzx4g3
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 80;

                    ;% rtB.o0uiwu2wn4
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 81;

                    ;% rtB.m5hwtguh1n
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 82;

                    ;% rtB.pqj4t3vzft
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 83;

                    ;% rtB.kg5nlp1vty
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 84;

                    ;% rtB.e4fhvpsn0a
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 85;

                    ;% rtB.kiowxcg1sw
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 88;

                    ;% rtB.fsb4j0khha
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 91;

                    ;% rtB.fa1rxjoibu
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 94;

                    ;% rtB.lp44qocih1
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 97;

                    ;% rtB.mynduz3xvt
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 100;

                    ;% rtB.mi1anjx3mq
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 103;

                    ;% rtB.kds1ep2sd0
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 106;

                    ;% rtB.ihcsgspswd
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 107;

                    ;% rtB.dkdpuf2nrz
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 108;

                    ;% rtB.oknc4qrqul
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 109;

                    ;% rtB.hp150xzlm5
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 110;

                    ;% rtB.duwuhux2st
                    section.data(68).logicalSrcIdx = 67;
                    section.data(68).dtTransOffset = 111;

                    ;% rtB.f45wytmhlu
                    section.data(69).logicalSrcIdx = 68;
                    section.data(69).dtTransOffset = 112;

                    ;% rtB.o250csv04h
                    section.data(70).logicalSrcIdx = 69;
                    section.data(70).dtTransOffset = 115;

                    ;% rtB.mw1ofaqc0d
                    section.data(71).logicalSrcIdx = 70;
                    section.data(71).dtTransOffset = 118;

                    ;% rtB.gvri4phsjb
                    section.data(72).logicalSrcIdx = 71;
                    section.data(72).dtTransOffset = 124;

                    ;% rtB.gu5gko2lp5
                    section.data(73).logicalSrcIdx = 72;
                    section.data(73).dtTransOffset = 127;

                    ;% rtB.akrbmyschb
                    section.data(74).logicalSrcIdx = 73;
                    section.data(74).dtTransOffset = 128;

                    ;% rtB.lcr4hfaiul
                    section.data(75).logicalSrcIdx = 74;
                    section.data(75).dtTransOffset = 129;

                    ;% rtB.mlkbjznxlc
                    section.data(76).logicalSrcIdx = 75;
                    section.data(76).dtTransOffset = 130;

                    ;% rtB.hf33apcafb
                    section.data(77).logicalSrcIdx = 76;
                    section.data(77).dtTransOffset = 131;

                    ;% rtB.i3qqkdiw05
                    section.data(78).logicalSrcIdx = 77;
                    section.data(78).dtTransOffset = 132;

                    ;% rtB.lnimvle1rj
                    section.data(79).logicalSrcIdx = 78;
                    section.data(79).dtTransOffset = 135;

                    ;% rtB.hdtg2mz21g
                    section.data(80).logicalSrcIdx = 79;
                    section.data(80).dtTransOffset = 136;

                    ;% rtB.i1avsg3ef3
                    section.data(81).logicalSrcIdx = 80;
                    section.data(81).dtTransOffset = 145;

                    ;% rtB.pz1o5ffnri
                    section.data(82).logicalSrcIdx = 81;
                    section.data(82).dtTransOffset = 148;

                    ;% rtB.o3faktraka
                    section.data(83).logicalSrcIdx = 82;
                    section.data(83).dtTransOffset = 151;

                    ;% rtB.i3xmajgkf0
                    section.data(84).logicalSrcIdx = 83;
                    section.data(84).dtTransOffset = 154;

                    ;% rtB.ddtcpvxvbu
                    section.data(85).logicalSrcIdx = 84;
                    section.data(85).dtTransOffset = 157;

                    ;% rtB.febx52uog3
                    section.data(86).logicalSrcIdx = 85;
                    section.data(86).dtTransOffset = 160;

                    ;% rtB.ay5hewygdd
                    section.data(87).logicalSrcIdx = 86;
                    section.data(87).dtTransOffset = 163;

                    ;% rtB.alzlbjc0as
                    section.data(88).logicalSrcIdx = 87;
                    section.data(88).dtTransOffset = 166;

                    ;% rtB.lgn5qxdsfl
                    section.data(89).logicalSrcIdx = 88;
                    section.data(89).dtTransOffset = 169;

                    ;% rtB.o2w2qidibo
                    section.data(90).logicalSrcIdx = 89;
                    section.data(90).dtTransOffset = 172;

                    ;% rtB.bfvnrwgw1h
                    section.data(91).logicalSrcIdx = 90;
                    section.data(91).dtTransOffset = 173;

                    ;% rtB.en0jsvv1cd
                    section.data(92).logicalSrcIdx = 91;
                    section.data(92).dtTransOffset = 174;

                    ;% rtB.eyyenf2ob2
                    section.data(93).logicalSrcIdx = 92;
                    section.data(93).dtTransOffset = 175;

                    ;% rtB.onfee4huot
                    section.data(94).logicalSrcIdx = 93;
                    section.data(94).dtTransOffset = 176;

                    ;% rtB.e0tzo2c4hh
                    section.data(95).logicalSrcIdx = 94;
                    section.data(95).dtTransOffset = 177;

                    ;% rtB.j3jivuya1i
                    section.data(96).logicalSrcIdx = 95;
                    section.data(96).dtTransOffset = 178;

                    ;% rtB.kswqxwm5fc
                    section.data(97).logicalSrcIdx = 96;
                    section.data(97).dtTransOffset = 181;

                    ;% rtB.py1jp4xfdb
                    section.data(98).logicalSrcIdx = 97;
                    section.data(98).dtTransOffset = 184;

                    ;% rtB.nbxandr1dq
                    section.data(99).logicalSrcIdx = 98;
                    section.data(99).dtTransOffset = 187;

                    ;% rtB.h4ublwxemc
                    section.data(100).logicalSrcIdx = 99;
                    section.data(100).dtTransOffset = 190;

                    ;% rtB.bcjcqbvmdf
                    section.data(101).logicalSrcIdx = 100;
                    section.data(101).dtTransOffset = 199;

                    ;% rtB.fsrrtwrymg
                    section.data(102).logicalSrcIdx = 101;
                    section.data(102).dtTransOffset = 202;

                    ;% rtB.aex35jzv0e
                    section.data(103).logicalSrcIdx = 102;
                    section.data(103).dtTransOffset = 205;

                    ;% rtB.ogdzjb4jan
                    section.data(104).logicalSrcIdx = 103;
                    section.data(104).dtTransOffset = 217;

                    ;% rtB.nbnq3nxxt1
                    section.data(105).logicalSrcIdx = 104;
                    section.data(105).dtTransOffset = 218;

                    ;% rtB.ny4fdqpjjc
                    section.data(106).logicalSrcIdx = 105;
                    section.data(106).dtTransOffset = 219;

                    ;% rtB.fs1sshlnh1
                    section.data(107).logicalSrcIdx = 106;
                    section.data(107).dtTransOffset = 220;

                    ;% rtB.hhre2rxku1
                    section.data(108).logicalSrcIdx = 107;
                    section.data(108).dtTransOffset = 221;

                    ;% rtB.pdlcsr0mtt
                    section.data(109).logicalSrcIdx = 108;
                    section.data(109).dtTransOffset = 224;

                    ;% rtB.exah40fyce
                    section.data(110).logicalSrcIdx = 109;
                    section.data(110).dtTransOffset = 233;

                    ;% rtB.ghgjlawphx
                    section.data(111).logicalSrcIdx = 110;
                    section.data(111).dtTransOffset = 242;

                    ;% rtB.kpztmnslrx
                    section.data(112).logicalSrcIdx = 111;
                    section.data(112).dtTransOffset = 251;

                    ;% rtB.pvuzvh4wal
                    section.data(113).logicalSrcIdx = 112;
                    section.data(113).dtTransOffset = 254;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
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
        nTotSects     = 4;
        sectIdxOffset = 1;

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
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.h1abylwox0
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 14;
            section.data(14)  = dumData; %prealloc

                    ;% rtDW.hscbc0octt.LoggedData
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.pfdn5tsup5.AQHandles
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 16;

                    ;% rtDW.bux0bm1vm5.AQHandles
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 30;

                    ;% rtDW.iw20iq135h.LoggedData
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 31;

                    ;% rtDW.oi4b5hlxk3.LoggedData
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 35;

                    ;% rtDW.bfstchyvk0.LoggedData
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 38;

                    ;% rtDW.g23vkedp5p.LoggedData
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 41;

                    ;% rtDW.ewg25jo1kp.LoggedData
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 44;

                    ;% rtDW.kmt2j0zhf4.LoggedData
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 47;

                    ;% rtDW.fqmnt2n3sq.LoggedData
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 50;

                    ;% rtDW.j421adr5dl.LoggedData
                    section.data(11).logicalSrcIdx = 11;
                    section.data(11).dtTransOffset = 53;

                    ;% rtDW.kvvcjgui0t.AQHandles
                    section.data(12).logicalSrcIdx = 12;
                    section.data(12).dtTransOffset = 56;

                    ;% rtDW.lhn5xaz053.AQHandles
                    section.data(13).logicalSrcIdx = 13;
                    section.data(13).dtTransOffset = 57;

                    ;% rtDW.djq4c1imrv.AQHandles
                    section.data(14).logicalSrcIdx = 14;
                    section.data(14).dtTransOffset = 58;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtDW.gtrkyqalzw
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.bcixyiccvs
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.azdfo1yqhk
                    section.data(3).logicalSrcIdx = 17;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% rtDW.m5ykicffnh
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.gqihoqfbig
                    section.data(2).logicalSrcIdx = 19;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.mzyyrqm3kv
                    section.data(3).logicalSrcIdx = 20;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.exrt0pkk0n
                    section.data(4).logicalSrcIdx = 21;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
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


    targMap.checksum0 = 449807628;
    targMap.checksum1 = 3424572996;
    targMap.checksum2 = 336135214;
    targMap.checksum3 = 2211097397;

