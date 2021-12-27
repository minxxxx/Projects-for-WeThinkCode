lang_zh_cn = {
	'test': '测试'
};
angular.module('starter.services', [])

/**
 * A simple example service that returns some data.
 */

// 翻译
.factory('Translation', function($scope) {
	// 随机一百以内的数
	alert(1);
	lang = lang_zh_cn;
	return function(word) {
		if (lang(word)) {
			return lang(word);
		}else{
			return "";
		}
	};
});