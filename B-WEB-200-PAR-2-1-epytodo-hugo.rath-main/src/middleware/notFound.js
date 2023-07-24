const db = require('../config/db');

exports.check_id = (req, res, next) => {
    const todo_id = req.params.id;

    if (!todo_id) {
        return res.status(500).json({ msg: 'Internal server error' });
    }

    db.execute('SELECT * FROM `todo` WHERE `id` = ?', [todo_id], (error, results, fields) => {
        if (error) {
            return res.status(500).json({ msg: 'Internal server error' });
        }

        if (results.length > 0) {
            next();
        } else {
            res.status(404).json({ msg: 'Not found' });
        }
    });
};

exports.check_user_id = (req, res, next) => {
    const user_id = req.params.id;

    if (!user_id) {
        return res.status(500).json({ msg: 'Internal server error' });
    }

    db.execute('SELECT * FROM `user` WHERE `id` = ?', [user_id], (error, results, fields) => {
        if (error) {
            return res.status(500).json({ msg: 'Internal server error' });
        }

        if (results.length > 0) {
            next();
        } else {
            res.status(404).json({ msg: 'Not found' });
        }
    });
};
