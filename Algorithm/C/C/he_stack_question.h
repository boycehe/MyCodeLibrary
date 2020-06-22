//
//  he_question.h
//  C
//
//  Created by heboyce on 2020/6/7.
//  Copyright © 2020 heboyce. All rights reserved.
//

#ifndef he_question_h
#define he_question_h

#include <stdio.h>
#include <stdbool.h>
/*
20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
bool isValidBrackets(char * s);

/*
 1021. 删除最外层的括号
 有效括号字符串为空 ("")、"(" + A + ")" 或 A + B，其中 A 和 B 都是有效的括号字符串，+ 代表字符串的连接。例如，""，"()"，"(())()" 和 "(()(()))" 都是有效的括号字符串。

如果有效字符串 S 非空，且不存在将其拆分为 S = A+B 的方法，我们称其为原语（primitive），其中 A 和 B 都是非空有效括号字符串。

给出一个非空有效字符串 S，考虑将其进行原语化分解，使得：S = P_1 + P_2 + ... + P_k，其中 P_i 是有效括号字符串原语。

对 S 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 S 。

 示例
    输入："(()())(())"
    输出："()()()"
    解释：
        输入字符串为 "(()())(())"，原语化分解得到 "(()())" + "(())"，
        删除每个部分中的最外层括号后得到 "()()" + "()" = "()()()"。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-outermost-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
char * removeOuterParentheses(char * s);


#endif /* he_question_h */
