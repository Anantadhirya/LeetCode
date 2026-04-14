/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    const ret = {};
    this.forEach((i) => {
        const key = fn(i);
        if(!ret[key]) ret[key] = []
        ret[key].push(i);
    });
    return ret;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */