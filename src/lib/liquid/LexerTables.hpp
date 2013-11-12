#ifndef __LIQUID_LEXERTABLE
#define __LIQUID_LEXERTABLE
namespace Liquid
{
    /// Table of delimiter characters
    static const bool LexerDelimiterTable[256] = {
/*     nul      soh      stx      etx      eot      enq      ack      bel  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*     bs       ht       nl       vt       np       cr       so       si   */
        0,       1,       1,       0,       0,       1,       0,       0,
/*     dle      dc1      dc2      dc3      dc4      nak      syn      etb */
        0,       0,       0,       0,       0,       0,       0,       0,
/*     can      em       sub      esc      fs       gs       rs       us  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*     sp        !        "        #        $        %        &        '  */
        1,       1,       1,       0,       0,       1,       1,       1,
/*      (        )        *        +        ,        -        .        /  */
        1,       1,       0,       0,       1,       0,       0,       0,
/*      0        1        2        3        4        5        6        7  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      8        9        :        ;        <        =        >        ?  */
        0,       0,       1,       0,       1,       1,       1,       0,
/*      @        A        B        C        D        E        F        G  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      H        I        J        K        L        M        N        O  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      P        Q        R        S        T        U        V        W  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      X        Y        Z        [        \        ]        ^        _  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      `        a        b        c        d        e        f        g  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      h        i        j        k        l        m        n        o  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      p        q        r        s        t        u        v        w  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      x        y        z        {        |        }        ~       del */
        0,       0,       0,       0,       1,       1,       0,       0,
    };

    
    /// Table of operator characters
    static const bool LexerOperatorTable[256] = {
/*     nul      soh      stx      etx      eot      enq      ack      bel  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*     bs       ht       nl       vt       np       cr       so       si   */
        0,       0,       0,       0,       0,       0,       0,       0,
/*     dle      dc1      dc2      dc3      dc4      nak      syn      etb */
        0,       0,       0,       0,       0,       0,       0,       0,
/*     can      em       sub      esc      fs       gs       rs       us  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*     sp        !        "        #        $        %        &        '  */
        0,       1,       0,       0,       0,       0,       0,       0,
/*      (        )        *        +        ,        -        .        /  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      0        1        2        3        4        5        6        7  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      8        9        :        ;        <        =        >        ?  */
        0,       0,       0,       0,       1,       1,       1,       0,
/*      @        A        B        C        D        E        F        G  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      H        I        J        K        L        M        N        O  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      P        Q        R        S        T        U        V        W  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      X        Y        Z        [        \        ]        ^        _  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      `        a        b        c        d        e        f        g  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      h        i        j        k        l        m        n        o  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      p        q        r        s        t        u        v        w  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      x        y        z        {        |        }        ~       del */
        0,       0,       0,       0,       0,       0,       1,       0,
    };

    /// Table of whitespace characters
    static const bool LexerWhitespaceTable[256] = {
/*     nul      soh      stx      etx      eot      enq      ack      bel  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*     bs       ht       nl       vt       np       cr       so       si   */
        0,       1,       1,       0,       0,       1,       0,       0,
/*     dle      dc1      dc2      dc3      dc4      nak      syn      etb */
        0,       0,       0,       0,       0,       0,       0,       0,
/*     can      em       sub      esc      fs       gs       rs       us  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*     sp        !        "        #        $        %        &        '  */
        1,       0,       0,       0,       0,       0,       0,       0,
/*      (        )        *        +        ,        -        .        /  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      0        0        2        3        4        5        6        7  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      8        9        :        ;        <        =        >        ?  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      @        A        B        C        D        E        F        G  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      H        I        J        K        L        M        N        O  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      P        Q        R        S        T        U        V        W  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      X        Y        Z        [        \        ]        ^        _  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      `        a        b        c        d        e        f        g  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      h        i        j        k        l        m        n        o  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      p        q        r        s        t        u        v        w  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      x        y        z        {        |        }        ~       del */
        0,       0,       0,       0,       0,       0,       0,       0,
    };


    /// Table of string wrapping characters
    static const bool LexerStringWrapperTable[256] = {
/*     nul      soh      stx      etx      eot      enq      ack      bel  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*     bs       ht       nl       vt       np       cr       so       si   */
        0,       0,       0,       0,       0,       0,       0,       0,
/*     dle      dc1      dc2      dc3      dc4      nak      syn      etb */
        0,       0,       0,       0,       0,       0,       0,       0,
/*     can      em       sub      esc      fs       gs       rs       us  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*     sp        !        "        #        $        %        &        '  */
        0,       0,       1,       0,       0,       0,       0,       1,
/*      (        )        *        +        ,        -        .        /  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      0        1        2        3        4        5        6        7  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      8        9        :        ;        <        =        >        ?  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      @        A        B        C        D        E        F        G  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      H        I        J        K        L        M        N        O  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      P        Q        R        S        T        U        V        W  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      X        Y        Z        [        \        ]        ^        _  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      `        a        b        c        d        e        f        g  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      h        i        j        k        l        m        n        o  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      p        q        r        s        t        u        v        w  */
        0,       0,       0,       0,       0,       0,       0,       0,
/*      x        y        z        {        |        }        ~       del */
        0,       0,       0,       0,       0,       0,       0,       0,
    };
}
#endif
