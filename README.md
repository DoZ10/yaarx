yaarx
=====

Yet Another Toolkit for Analysis of ARX Cryptographic Algorithms

YAARX is a set of programs for the differential analysis of ARX cryptographic algorithms. 

/*! \mainpage Yet Another Toolkit for Analysis of ARX Cryptographic Algorithms
 *
 * \section what_sec What is YAARX
 * 
 * YAARX is a set of programs for the differential analysis of ARX
 * cryptographic algorithms. The latter represent a broad class of
 * symmetric-key algorithms designed by combining a small set of simple
 * operations such as modular addition, bit rotation, bit shift and
 * XOR. More notable representatives of the ARX class of algorithms
 * are the block ciphers <a href="https://en.wikipedia.org/wiki/FEAL">FEAL</a>, 
 * <a href="https://en.wikipedia.org/wiki/RC5">RC5</a>, 
 * <a href="https://en.wikipedia.org/wiki/Tiny_Encryption_Algorithm">TEA</a> and 
 * <a href="https://en.wikipedia.org/wiki/XTEA">XTEA</a>, the stream cipher
 * <a href="https://en.wikipedia.org/wiki/Salsa20">Salsa20</a>, the hash functions 
 * <a href="https://en.wikipedia.org/wiki/MD4">MD4</a>, 
 * <a href="https://en.wikipedia.org/wiki/MD5">MD5</a>, 
 * <a href="https://en.wikipedia.org/wiki/Skein_%28hash_function%29">Skein</a> and 
 * <a href="https://en.wikipedia.org/wiki/BLAKE_%28hash_function%29">BLAKE</a> 
 * as well as the recently proposed hash function for short messages 
 * <a href="https://131002.net/siphash/">SipHash</a>.  
 * 
 * 
 * \section why_sec How Does it Compare to Other ARX Tools
 * 
 * YAARX complements existing toolkits such
 * as <a href="http://www.di.ens.fr/~leurent/arxtools.html" >ARXtools</a>
 * and significantly extends others, such
 * as <a href="http://www.ecrypt.eu.org/tools/s-function-toolkit">The
 * S-function Toolkit</a>. More specifically, YAARX provides methods for the computation of
 * the differential probabilities of various ARX operations (XOR, modular
 * addition, multiplication, bit shift, bit rotation) as well as of several larger
 * components built from them. YAARX also provides means to search for 
 * high-probability differential trails in ARX algorithms in a fully automatic way. 
 * The latter has been a notoriously difficult task for ciphers that do not have
 * S-boxes, such as ARX. 
 * 
 * \section how_sec What Can YAARX Do for You
 *
 * YAARX can help the cryptanalyst in the process of analyzing ARX-based
 * constructions in at least two ways. 
 * 
 * \subsection scenario1_sec Using the Tools Directly
 * 
 * One way is to use the tools directly to compute differential
 * probabilities for a target cipher. To this end YAARX provides a set of
 * programs for the computation of the differential probabilities (DP) of
 * several operations with user provided inputs. Such are for example the
 * programs for computing the DP of modular addition, XOR, bit shift, 
 * etc.: \ref adp_xor, \ref xdp_add, \ref adp_xor3, \ref adp_xor_fixed_input, \ref adp_rsh,
 * \ref adp_lsh, \ref max_adp_xor, \ref max_xdp_add, \ref max_adp_xor3, \ref max_adp_xor_fixed_input,
 * \ref eadp_tea_f, \ref max_eadp_tea_f .
 * 
 * A conceivable scenario in this category would be the case in which the cryptanalyst
 * constructs a differential characteristic by hand and wants to estimate
 * its probability by computing the probabilities with which differences 
 * propagate through the ARX operations. In this case YAARX can provide 
 * answer to questions such as: 
 * 
 * <ul>
 * <li>
 * Given input differences \f$da\f$ and \f$db\f$ to an operation
 * \f$F\f$, and an output difference \f$dc\f$, what is the probability
 * of the differential \f$(da,~ db \rightarrow dc)\f$?
 * </li>
 * <li>
 * Given input differences \f$da\f$ and \f$db\f$ to \f$F\f$, what
 * is the output difference \f$dc\f$ that has maximum probability?
 * </li>
 * <li>
 * Given an input difference \f$da\f$ and an input value \f$b\f$
 * to \f$F\f$ and an output difference \f$dc\f$, what is the probability
 * of the differential \f$(da,~ b \rightarrow dc)\f$?
 * </li>
 * <li>
 * Given input difference \f$da\f$ and a set of input differences
 * \f$\{db_0,~db_1,\ldots\}\f$ to \f$F\f$, and an output difference
 * \f$dc\f$, what is the probability of the differential \f$(da,~
 * \{db_0,~db_1,\ldots\} \rightarrow dc)\f$?
 * </li>
 * <li>
 * etc. ...
 * </li>
 * </ul>
 * 
 * The differences \f$da\f$, \f$db\f$ and \f$dc\f$ can be
 * XOR or additive (ADD) differences and the operation \f$F\f$ can either be
 * one of the basic ARX operation, such as XOR, addition, etc. or a
 * larger component e.g. a sequence of bit shift and XOR or of addition,
 * rotation and XOR.
 * 
 * \subsection scenario2_sec Modifying the Source Code
 * 
 * The second way in which YAARX can be useful would require a bit more effort
 * and some programming literacy on the part of the cryptanalyst. The idea is,
 * prior to  using one of the YAARX tools, to first modify it
 * according to ones' specific needs. This scenario is realistic in a
 * case in which none of the YAARX tools is capable of directly addressing 
 * a problem for a given target cipher.
 * 
 * Scenarios in this category are likely to occur for example when one wants to automatically search
 * for differential trails in a given cipher. While YAARX supports a
 * general strategy for automatic search of trails, that is potentially
 * applicable to many ARX algorithms, it is implemented for two specific
 * ciphers, namely 
 * <a href="https://en.wikipedia.org/wiki/Tiny_Encryption_Algorithm">TEA</a> and 
 * <a href="https://en.wikipedia.org/wiki/XTEA">XTEA</a>:
 * \ref tea_add_threshold_search, \ref xtea_add_threshold_search, \ref xtea_xor_threshold_search. 
 * Since the algorithmic technique
 * underlying these implementations is general, the latter can be applied
 * to other ARX algorithms after appropriate modifications. To facilitate this 
 * process, the source code is accompanied by extensive 
 * <a href="file:///home/vpv/skcrypto/trunk/work/src/yaarx/doc/html/files.html">documentation</a>.
 * 
 * \section compilation_sec Compilation
 *
 * For successful compilation it is required to install the development version of the 
 * GNU Scientific Library (GSL) and the Multiprecision arithmetic library (GMP) developers tools . 
 * Under Ubuntu/Debian Linux the name of the packages are resp. libgsl0-dev and libgmp-dev .
 *
 * After downloading the YAARX source code, it can be compiled by running the make 
 * command from within the top directory of the source tree. The pre-compiled programs 
 * are stored in the ./bin directoy . 
 *
 * \section tools_sec The YAARX Tools
 *
 * A list of the tools provided by YAARX, together with
 * their computaional complexities is given in the table below. 
 * For more details on a specific algorithm refer to the
 * <a href="file:///home/vpv/skcrypto/trunk/work/src/yaarx/doc/html/files.html">documentation</a>.
 * <br>
 * <br>
 * 
 * <table border="1">
 * <tr>
 * <td><b>\f$\Delta\f$ Operator</b></td>
 * <td><b>Algorithm</b></td>
 * <td><b>Description</b>, (DP = differential probability, ADD = modular addition)</td>
 * <td><b>Complexity</b>, (\f$n\f$ = word size, bits)</td>
 * </tr>
 *
 * <tr>
 * <td>\f$+\f$</td>
 * <td>\f$\mathrm{adp}^{\ll}(da \rightarrow db)\f$</td>
 * <td>The ADD DP of left shift (LSH).</td>
 * <td>\f$O(1)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$+\f$</td>
 * <td>\f$\mathrm{adp}^{\gg}(da \rightarrow db)\f$</td>
 * <td>The ADD DP of right shift (RSH).</td>
 * <td>\f$O(1)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$\oplus\f$</td>
 * <td>\f$\mathrm{xdp}^{+}(da,db \rightarrow dc)\f$</td>
 * <td>The XOR DP (XDP) of ADD.</td>
 * <td>\f$O(n)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$+\f$</td>
 * <td>\f$\mathrm{adp}^{\oplus}(da,db \rightarrow dc)\f$</td>
 * <td>The ADD DP (ADP) of XOR.</td>
 * <td>\f$O(n)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$+\f$</td>
 * <td>\f$\mathrm{adp}^{\oplus}_{\mathrm{FI}}(a,db \rightarrow db)\f$</td>
 * <td>The ADD DP of XOR with one fixed input.</td>
 * <td>\f$O(n)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$+\f$</td>
 * <td>\f$\mathrm{adp}^{3\oplus}(da,db,dc \rightarrow dd)\f$</td>
 * <td>The ADD DP of XOR with three inputs.</td>
 * <td>\f$O(n)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$+\f$</td>
 * <td>\f$\mathrm{adp}^{\gg\oplus}(da,db \rightarrow dc)\f$</td>
 * <td>The ADD DP of RSH followed by XOR.</td>
 * <td>\f$O(n)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$+\f$</td>
 * <td>\f$\mathrm{eadp}^{F}(da \rightarrow dd)\f$.</td>
 * <td>The expected additive DP (EADP) of the F-function of TEA, averaged over all round keys and constants: \f$F(k_0,k_1,\delta |~ x) = ((x \ll 4) + k_0) \oplus (x + \delta) \oplus ((x \gg 5) + k_1)\f$.</td>
 * <td>\f$O(n)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$+\f$</td>
 * <td>\f$\mathrm{adp}^{F'}(k_0, k_1, \delta |~ da \rightarrow db)\f$</td>
 * <td>The additive DP (ADP) of a modified version of the F-function of TEA with the shift operations removed: \f$F'(k_0, k_1, \delta |~ x) = (x + k_0) \oplus (x + \delta) \oplus (x + k_1)\f$. </td>
 * <td>\f$O(n)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$+\f$</td>
 * <td>\f$\mathrm{adp}^{\mathrm{ARX}}(r,da,db,dd \rightarrow de)\f$</td>
 * <td>The ADD DP of the sequence of operations ADD, ROT by \f$r\f$ positions, XOR.</td>
 * <td>\f$O(4n)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$\oplus\f$</td>
 * <td>\f$\max_{dc}~\mathrm{xdp}^{+}(da, db \rightarrow dc)\f$</td>
 * <td>The maximum XOR DP of ADD.</td>
 * <td>\f$O(n) \le c \ll O(2^n)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$+\f$</td>
 * <td>\f$\max_{dc}~\mathrm{adp}^{\oplus}(da, db \rightarrow dc)\f$</td>
 * <td>The maximum ADD DP of XOR.</td>
 * <td>\f$O(n) \le c \ll O(2^n)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$+\f$</td>
 * <td>\f$\max_{dc}~\mathrm{adp}^{\oplus}_{\mathrm{FI}}(a, db \rightarrow dc)\f$.</td>
 * <td>The maximum ADD DP of XOR with one fixed input:</td>
 * <td>\f$O(n) \le c \ll O(2^n)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$+\f$</td>
 * <td>\f$\max_{dd}~\mathrm{adp}^{3\oplus}(da, db, dc \rightarrow dd)\f$</td>
 * <td>The maximum ADD DP of XOR with three inputs:</td>
 * <td>\f$O(n) \le c \ll O(2^n)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$+\f$</td>
 * <td>\f$\max_{dd}~\mathrm{adp}^{\oplus}_{\mathrm{SET}}(da, db, \{{dc}_0, {dc}_1, \ldots\} \rightarrow dd)\f$</td>
 * <td>The maximum ADD DP of XOR with three inputs, where one of the inputs satisfies a \em set of ADD differences.</td>
 * <td>\f$O(n) \le c \ll O(2^n)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$\oplus\f$</td>
 * <td>\f$\max_{de}~\mathrm{adp}^{\mathrm{ARX}}(r, da, db, dd \rightarrow de)\f$</td>
 * <td>The maximum ADD DP of ARX.</td>
 * <td>\f$O(n) \le c \ll O(2^n)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$+\f$</td>
 * <td>\f$\max_{dd} \mathrm{eadp}^{F}(da \rightarrow dd)\f$</td>
 * <td>The maximum expected additive DP (EADP) of the F-function of TEA, averaged over all round keys and constants: \f$ F(x) = ((x \ll 4) + k_0) \oplus (x + \delta) \oplus ((x \gg 5) + k_1)\f$.</td>
 * <td>\f$ O(n) \le c \ll O(2^n)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$+\f$</td>
 * <td>\f$\mathrm{adp}^{F}(k_0, k_1, \delta |~ da \rightarrow dd)\f$</td>
 * <td>The ADD DP of the F-function of TEA for a fixed key and round constants: \f$F(k_0, k_1, \delta |~ x) = ((x \ll 4) + k_0) \oplus (x + \delta) \oplus ((x \gg 5) + k_1)\f$.</td>
 * <td>\f$ O(n) \ll c \le O(2^n)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$\oplus\f$</td>
 * <td>\f$\mathrm{xdp}^{F}(k_0, k_1, \delta |~ da \rightarrow dd)\f$.</td>
 * <td>The XOR DP of the F-function of TEA for a fixed key and round constants: \f$F(k_0, k_1, \delta |~ x) = ((x \ll 4) + k_0) \oplus (x + \delta) \oplus ((x \gg 5) + k_1)\f$.</td>
 * <td>\f$ O(n) \ll c \le O(2^n)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$+\f$</td>
 * <td>\f$\mathrm{adp}^{F}(k, \delta |~ da \rightarrow dd)\f$.</td>
 * <td>The ADD DP of the F-function of XTEA for a fixed key and round constants: \f$F(k, \delta |~ x)  = ((((x \ll 4) \oplus (x \gg 5)) + x) \oplus (k + \delta)\f$.</td>
 * <td>\f$ O(n) \ll c \le O(2^n) \f$.</td>
 * </tr>
 *
 * <tr>
 * <td>\f$\oplus\f$</td>
 * <td>\f$\mathrm{xdp}^{F}(k, \delta |~ da \rightarrow dd)\f$.</td>
 * <td>The XOR DP of the F-function of XTEA for a fixed key and round constants: \f$F(k, \delta |~ x)  = ((((x \ll 4) \oplus (x \gg 5)) + x) \oplus (k + \delta)\f$.</td>
 * <td>\f$ O(n) \ll c \le O(2^n)\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$+\f$</td>
 * <td>\f$\mathrm{pDDT}~\mathrm{adp}^{\oplus}\f$</td>
 * <td>Partial difference distribution table (pDDT) for \f$\mathrm{adp}^{\oplus}\f$ for a fixed probability threshold \f$p_\mathrm{thres}\f$</td>
 * <td>\f$c = f(p_\mathrm{thres})\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$\oplus\f$</td>
 * <td>\f$\mathrm{pDDT}~\mathrm{xdp}^{+}\f$</td>
 * <td>Partial difference distribution table (pDDT) for \f$\mathrm{xdp}^{+}\f$ for a fixed probability threshold \f$p_\mathrm{thres}\f$</td>
 * <td>\f$c = f(p_\mathrm{thres})\f$</td>
 * </tr>
 *
 * <tr>
 * <td>\f$+\f$</td>
 * <td><code>tea_add_threshold_search</code></td>
 * <td>Automatic search for ADD differential trails in block cipher TEA.</td>
 * <td></td>
 * </tr>
 *
 * <tr>
 * <td>\f$+\f$</td>
 * <td><code>xtea_add_threshold_search</code></td>
 * <td>Automatic search for ADD differential trails in block cipher XTEA.</td>
 * <td></td>
 * </tr>
 * <tr>
 * <td>\f$\oplus\f$</td>
 * <td><code>xtea_xor_threshold_search</code></td>
 * <td>Automatic search for XOR differential trails in block cipher XTEA.</td>
 * <td></td>
 * </tr>
 *
 * </table>
 *
 * \section copyright_sec Copyright
 *
 * 
 * YAARX is developed in
 * the <a href="http://wwwen.uni.lu/research/fstc/laboratory_of_algorithmics_cryptology_and_security_lacs">Laboratory
 * of Algorithmics, Cryptology and Security</a> (LACS)
 * of <a href="http://wwwen.uni.lu/">Luxembourg University</a> and is
 * licensed under <a href="https://www.gnu.org/licenses/">GPL</a> (c) 2012-2013.
 * 
 * <br>
 */
