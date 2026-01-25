// a h y j a k h
// g h e c e c g k a e m
// m m m e r m e
function StringChallenge(str) {
    let mapping = {};
    for (let i = 0; i < str.length; ++i) {
        let char = str[i];
        if (!mapping[char]) {
            mapping[char] = [];
        }
        mapping[char].push(i);
    }
    let result = 0;
    for (let key in mapping) {
        let positions = mapping[key];
        for (let i = 0; i < positions.length - 1; ++i) {
            for (let j = i + 1; j < positions.length; ++j) {
                let substr = str.substr(positions[i] + 1, positions[j] - positions[i] - 1);
                let myset = new Set(substr);
                result = Math.max(result, myset.size);
            }
        }
    }
    return result;

}
console.log(StringChallenge("mmmerme")); // 3